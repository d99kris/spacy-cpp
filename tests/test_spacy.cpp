// test_spacy.cpp
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
    // Spacy
    Spacy::Spacy spacy;

    // Spacy::load
    Spacy::Nlp nlp = spacy.load("en_core_web_sm");

    // Spacy::attrs
    Spacy::Attrs attrs = spacy.attrs();
  }
  catch(const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  return rv;
}
