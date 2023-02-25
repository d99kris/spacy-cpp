// spacy.h
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#pragma once

#include <memory>
#include <string>

#include "pyobjectptr.h"

namespace Spacy
{
  class Attrs;
  class Nlp;
  class Python;

  class Spacy
  {
  public:
    Spacy();
    virtual ~Spacy();

    Nlp load(const std::string& p_model) const;
    const Attrs& attrs();

  private:
    std::shared_ptr<Python> m_python;
    PyObjectPtr m_spacy;
    std::shared_ptr<Attrs> m_attrs;
  };
}

#ifdef SPACY_HEADER_ONLY
#include "spacy.cpp"
#endif
