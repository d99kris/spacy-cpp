// test_doc.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include <iostream>
#include <spacy/spacy>
#include "unittest.h"

int main()
{
  int rv = 0;

  try
  {
    // Prereq
    Spacy::Spacy spacy;
    Spacy::Nlp nlp = spacy.load("en_core_web_sm");
    Spacy::Attrs attrs = spacy.attrs();

    // Doc
    {
      Spacy::Doc doc = nlp.parse("Some text");
    }

    // Doc::count_by
    {
      Spacy::Doc doc = nlp.parse("apple apple orange banana");
      std::map<long, long> counts = doc.count_by(spacy.attrs().ORTH());
      unittest::ExpectEqual(long, counts[nlp.vocab().strings().add("apple")], 2);
      unittest::ExpectEqual(long, counts[nlp.vocab().strings().add("orange")], 1);
      unittest::ExpectEqual(long, counts[nlp.vocab().strings().add("banana")], 1);
    }
    
    // Doc::ents
    {
      Spacy::Doc doc = nlp.parse("Mr. Best flew to New York on Saturday morning.");
      std::vector<Spacy::Span> ents = doc.ents();
      unittest::ExpectEqual(std::string, ents[0].label_(), "PERSON");
      unittest::ExpectEqual(std::string, ents[0].text(), "Best");
    }
    
    // Doc::has_vector
    {
      Spacy::Doc doc = nlp.parse("I like apples");
      unittest::ExpectTrue(doc.has_vector());
    }

    // Doc::is_parsed
    {
      Spacy::Doc doc = nlp.parse("I like apples");
      unittest::ExpectTrue(doc.is_parsed());
    }

    // Doc::is_tagged
    {
      Spacy::Doc doc = nlp.parse("I like apples");
      unittest::ExpectTrue(doc.is_tagged());
    }

    // Doc::noun_chunks
    {
      Spacy::Doc doc = nlp.parse("A phrase with another phrase occurs.");
      std::vector<Spacy::Span> chunks = doc.noun_chunks();
      unittest::ExpectEqual(std::string, chunks[0].text(), "A phrase");
      unittest::ExpectEqual(std::string, chunks[1].text(), "another phrase");
    }
    
    // Doc::sentiment
    {
      Spacy::Doc doc = nlp.parse("I like apples");
      double sentiment = doc.sentiment();
      (void)(sentiment);
    }

    // Doc::sents
    {
      Spacy::Doc doc = nlp.parse("This is a sentence. Here's another...");
      std::vector<Spacy::Span> sents = doc.sents();
      unittest::ExpectEqual(size_t, sents.size(), 2);
      unittest::ExpectEqual(std::string, sents.at(0).root().text(), "is");
      unittest::ExpectEqual(std::string, sents.at(1).root().text(), "'s");
    }

    // Doc::similarity
    {
      Spacy::Doc apples = nlp.parse("I like apples");
      Spacy::Doc oranges = nlp.parse("I like oranges");
      double apples_oranges = apples.similarity(oranges);
      double oranges_apples = oranges.similarity(apples);
      unittest::ExpectEqual(double, apples_oranges, oranges_apples);
    }
    
    // Doc::text
    {
      Spacy::Doc doc = nlp.parse("I like apples");
      unittest::ExpectEqual(std::string, doc.text(), "I like apples");
    }

    // Doc::text_with_ws
    {
      Spacy::Doc doc = nlp.parse("I like apples");
      unittest::ExpectEqual(std::string, doc.text_with_ws(), "I like apples");
    }

    // Doc::tokens
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      unittest::ExpectEqual(std::string, doc.tokens().at(0).text(), "Give");
      unittest::ExpectEqual(std::string, doc.tokens().at(doc.tokens().size() - 1).text(), ".");
      unittest::ExpectEqual(size_t, doc.tokens().size(), 7);
    }

    // Doc::vector_norm
    {
      Spacy::Doc doc1 = nlp.parse("I like apples");
      Spacy::Doc doc2 = nlp.parse("I like oranges");
      unittest::ExpectTrue(doc1.vector_norm() != doc2.vector_norm());
    }
  }
  catch(const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  return rv;
}
