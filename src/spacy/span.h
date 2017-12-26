// span.h
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#pragma once

#include <string>
#include <vector>

#include "pyobjectptr.h"

namespace Spacy
{
  class Doc;
  class Python;
  class Token;

  class Span
  {
    friend Doc;
    friend Python;
    
  public:
    virtual ~Span();

    Doc* doc();
    long label();
    std::string label_();
    std::string lemma_();
    std::string orth_();
    Token root();
    double sentiment();
    std::string text();
    std::string text_with_ws();
    std::vector<Token> tokens();
    double vector_norm();
    
  private:
    Span(PyObjectPtr p_span, Doc* p_parent = nullptr);

    void set_parent(Doc* p_parent);
    
  private:
    PyObjectPtr m_span;
    Doc* m_parent;
  };
}

#ifdef SPACY_HEADER_ONLY
#include "span.cpp"
#endif
