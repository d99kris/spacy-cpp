// vocab.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "vocab.h"

#include <string>

#include "python.h"
#include "stringstore.h"

namespace Spacy
{
  Vocab::~Vocab()
  {
  }

  StringStore Vocab::strings() const
  {
    return StringStore(Python::get_attr_value<PyObjectPtr>(m_vocab, "strings"));
  }

  Vocab::Vocab(PyObjectPtr p_vocab)
    : m_vocab(p_vocab)
  {
  }
}
