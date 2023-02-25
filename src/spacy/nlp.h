// nlp.h
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
  class Doc;
  class Spacy;
  class Vocab;

  class Nlp
  {
    friend Spacy;

  public:
    virtual ~Nlp();

    Doc parse(const std::string& p_text) const;
    Vocab vocab() const;

  private:
    Nlp(PyObjectPtr p_nlp);

  private:
    PyObjectPtr m_nlp;
  };
}

#ifdef SPACY_HEADER_ONLY
#include "nlp.cpp"
#endif
