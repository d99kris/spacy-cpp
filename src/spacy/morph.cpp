// morph.cpp
//
// URL:      https://github.com/Alfredlang1989/spacy-cpp
//
// Copyright (C) 2022 Alfred Lang
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "morph.h"

#include <string>

#include "python.h"
#include "stringstore.h"
#include <iostream>


namespace Spacy
{
  Morph::~Morph()
  {
  }

  Morph::Morph()
  {
  }


  Morph::Morph(PyObjectPtr p_morph)
    : m_morph(p_morph)
  {
  }


 std::string Morph::to_string() const
  {
   return Python::call_method<std::string>(m_morph, "__str__");
  }

}
