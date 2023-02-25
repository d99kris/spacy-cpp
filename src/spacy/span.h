// span.h
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017-2020 Kristofer Berggren
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

    const Doc* doc() const;
    long label() const;
    std::string label_() const;
    std::string lemma_() const;
    std::string orth_() const;
    Token root() const;
    double sentiment() const;
    std::string text() const;
    std::string text_with_ws() const;
    std::vector<Token> tokens() const;
    double vector_norm() const;

  private:
    Span(PyObjectPtr p_span, const Doc* p_parent = nullptr);

    void set_parent(Doc* p_parent);

  private:
    PyObjectPtr m_span;
    const Doc* m_parent;
  };
}

#ifdef SPACY_HEADER_ONLY
#include "span.cpp"
#endif
