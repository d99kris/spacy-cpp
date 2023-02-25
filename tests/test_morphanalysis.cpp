// test_morphanalysis.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2023 Kristofer Berggren
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

    // Nlp::parse
    Spacy::Doc doc = nlp.parse("I love apples.");
    auto tokens = doc.tokens();

    // MorphAnalysis::to_dict
    {
      Spacy::MorphAnalysis morph = tokens.at(0).morph();
      std::map<std::string, std::string> dict = morph.to_dict();
      unittest::ExpectEqual(std::string, dict["Case"], "Nom");
      unittest::ExpectEqual(std::string, dict["Number"], "Sing");
      unittest::ExpectEqual(std::string, dict["Person"], "1");
      unittest::ExpectEqual(std::string, dict["PronType"], "Prs");
    }

    // MorphAnalysis::get
    {
      Spacy::MorphAnalysis morph = tokens.at(1).morph();
      unittest::ExpectEqual(std::string, morph.get("Tense").at(0), "Pres");
      unittest::ExpectEqual(std::string, morph.get("VerbForm").at(0), "Fin");
    }

    // MorphAnalysis::str
    {
      Spacy::MorphAnalysis morph = tokens.at(2).morph();
      unittest::ExpectEqual(std::string, morph.str(), "Number=Plur");
    }
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  return rv;
}
