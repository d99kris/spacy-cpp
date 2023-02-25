// token.h
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017-2023 Kristofer Berggren
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
  class MorphAnalysis;
  class Python;
  class Span;

  class Token
  {
    friend Doc;
    friend Python;
    friend Span;

  public:
    virtual ~Token();

    bool check_flag(long p_attr) const;
    std::vector<Token> children() const;
    long cluster() const;
    long dep() const;
    std::string dep_() const;
    std::string ent_iob_() const;
    bool has_vector() const;
    Token head() const;
    long i() const;
    long idx() const;
    bool is_alpha() const;
    bool is_ascii() const;
    bool is_bracket() const;
    bool is_digit() const;
    bool is_left_punct() const;
    bool is_lower() const;
    bool is_oov() const;
    bool is_punct() const;
    bool is_quote() const;
    bool is_right_punct() const;
    bool is_space() const;
    bool is_stop() const;
    bool is_title() const;
    bool is_upper() const;
    long lang() const;
    std::string lang_() const;
    long lemma() const;
    std::string lemma_() const;
    bool like_email() const;
    bool like_num() const;
    bool like_url() const;
    long lower() const;
    std::string lower_() const;
    MorphAnalysis morph() const;
    Token nbor(long p_i = 1) const;
    long norm() const;
    std::string norm_() const;
    long orth() const;
    std::string orth_() const;
    long pos() const;
    std::string pos_() const;
    double prob() const;
    double rank() const;
    double sentiment() const;
    long shape() const;
    std::string shape_() const;
    long tag() const;
    std::string tag_() const;
    std::string text() const;
    std::string text_with_ws() const;
    std::string whitespace_() const;

  private:
    explicit Token(PyObjectPtr p_token);

    PyObjectPtr get_ptr() const;

  private:
    PyObjectPtr m_token;
  };
}

#ifdef SPACY_HEADER_ONLY
#include "token.cpp"
#endif
