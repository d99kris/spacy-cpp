//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2022 Alfred Lang
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#pragma once

#include <string>
#include "token.h"
#include "pyobjectptr.h"
#include <map>

namespace Spacy
{
  class Morph
  {
    friend Token;

  public:
    virtual ~Morph();
   
   explicit Morph(PyObjectPtr p_morph);
    Morph();
    std::string to_string() const;
    std::string  get(std::string feat);
    std::map<std::string,std::string> to_dict();
  private:
    PyObjectPtr m_morph;
  };
}

#ifdef SPACY_HEADER_ONLY
#include "morph.cpp"
#endif

