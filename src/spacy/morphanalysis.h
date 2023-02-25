// morphanalysis.h
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2023 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#pragma once

#include <map>
#include <string>
#include <vector>

#include "pyobjectptr.h"

namespace Spacy
{
  class Python;
  class Token;

  class MorphAnalysis
  {
    friend Python;
    friend Token;

  public:
    virtual ~MorphAnalysis();

    std::vector<std::string> get(const std::string& p_field) const;
    std::string str() const;
    std::map<std::string, std::string> to_dict() const;

  private:
    MorphAnalysis(PyObjectPtr p_morphanalysis);

  private:
    PyObjectPtr m_morphanalysis;
  };
}

#ifdef SPACY_HEADER_ONLY
#include "morphanalysis.cpp"
#endif
