// test_attrs.cpp
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
    Spacy::Attrs attrs = spacy.attrs();

    // Attrs
    {
      unittest::ExpectTrue(attrs.IS_ALPHA() != attrs.IS_ASCII());
    }
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  return rv;
}
