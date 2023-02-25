// vocab.h
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
  class Nlp;
  class StringStore;

  class Vocab
  {
    friend Nlp;

  public:
    virtual ~Vocab();

    StringStore strings() const;

  private:
    Vocab(PyObjectPtr p_vocab);

  private:
    PyObjectPtr m_vocab;
  };
}

#ifdef SPACY_HEADER_ONLY
#include "vocab.cpp"
#endif
