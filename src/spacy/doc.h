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

    std::map<long, long> count_by(long p_attr);
    std::vector<Span> ents();
    bool has_vector();
    bool is_parsed();
    bool is_tagged();
    std::vector<Span> noun_chunks();
    double sentiment();
    std::vector<Span> sents();
    double similarity(const Doc& p_doc);
    std::string text();
    std::string text_with_ws();
    std::vector<Token> tokens();
    double vector_norm();
    
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
