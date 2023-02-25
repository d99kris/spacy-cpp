// stringstore.h
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#pragma once

#include <string>

#include "pyobjectptr.h"

namespace Spacy
{
  class Vocab;

  class StringStore
  {
    friend Vocab;

  public:
    virtual ~StringStore();

    long add(const std::string& p_str) const;

  private:
    StringStore(PyObjectPtr p_stringstore);

  private:
    PyObjectPtr m_stringstore;
  };
}

#ifdef SPACY_HEADER_ONLY
#include "stringstore.cpp"
#endif
