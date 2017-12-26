// test_span.cpp
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

    // Span
    {
      Spacy::Span span = nlp.parse("This is a sentence.").sents().at(0);
    }

    // Span::label
    {
      Spacy::Span span = nlp.parse("Mr. Best flew to New York on Saturday morning.").ents().at(0);
      unittest::ExpectEqual(long, span.label(), nlp.vocab().strings().add("PERSON"));
    }

    // Span::label_
    {
      Spacy::Span span = nlp.parse("Mr. Best flew to New York on Saturday morning.").ents().at(0);
      unittest::ExpectEqual(std::string, span.label_(), "PERSON");
    }

    // Span::lemma_
    {
      Spacy::Span span = nlp.parse("Car").sents().at(0);
      unittest::ExpectEqual(std::string, span.lemma_(), "car");
    }

    // Span::orth
    {
      Spacy::Span span = nlp.parse("apple").sents().at(0);
      unittest::ExpectEqual(std::string, span.orth_(), "apple");
    }

    // Span::root
    {
      Spacy::Span span = nlp.parse("This is a sentence.").sents().at(0);
      unittest::ExpectEqual(std::string, span.root().text(), "is");
    }

    // Span::sentiment
    {
      Spacy::Span span = nlp.parse("This is a sentence.").sents().at(0);
      double sentiment = span.sentiment();
      (void)(sentiment);
    }
    
    // Span::text
    {
      Spacy::Span span = nlp.parse("I like apples.").sents().at(0);
      unittest::ExpectEqual(std::string, span.text(), "I like apples.");
    }

    // Span::text_with_ws
    {
      Spacy::Span span = nlp.parse("I like apples.").sents().at(0);
      unittest::ExpectEqual(std::string, span.text_with_ws(), "I like apples.");
    }
    
    // Span::tokens
    {
      Spacy::Span span = nlp.parse("Give it back! He pleaded.").sents().at(0);
      unittest::ExpectEqual(std::string, span.tokens().at(0).text(), "Give");
      unittest::ExpectEqual(std::string, span.tokens().at(span.tokens().size() - 1).text(), "!");
      unittest::ExpectEqual(size_t, span.tokens().size(), 4);
    }

    // doc.vector_norm
    {
      Spacy::Span span1 = nlp.parse("I like apples. I like oranges.").sents().at(0);
      Spacy::Span span2 = nlp.parse("I like apples. I like oranges.").sents().at(1);
      unittest::ExpectTrue(span1.vector_norm() != span2.vector_norm());
    }
  }
  catch(const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  return rv;
}
