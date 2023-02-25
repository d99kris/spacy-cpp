// doc.h
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#pragma once

#include <map>
#include <vector>

#include "pyobjectptr.h"

namespace Spacy
{
  class Nlp;
  class Span;
  class Token;

  class Doc
  {
    friend Nlp;

  public:
    virtual ~Doc();

    std::map<long, long> count_by(long p_attr) const;
    std::vector<Span> ents() const;
    bool has_vector() const;
    bool is_parsed() const;
    bool is_tagged() const;
    std::vector<Span> noun_chunks() const;
    double sentiment() const;
    std::vector<Span> sents() const;
    double similarity(const Doc& p_doc) const;
    std::string text() const;
    std::string text_with_ws() const;
    std::vector<Token> tokens() const;
    double vector_norm() const;

  private:
    Doc(PyObjectPtr p_doc);

    PyObjectPtr get_ptr() const;

  private:
    PyObjectPtr m_doc;
  };
}

#ifdef SPACY_HEADER_ONLY
#include "doc.cpp"
#endif
