// token.h
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
  class Span;

  class Token
  {
    friend Doc;
    friend Python;
    friend Span;
    
  public:
    virtual ~Token();

    bool check_flag(long p_attr);
    std::vector<Token> children();
    long cluster();
    long dep();
    std::string dep_();
    std::string ent_iob_();
    bool has_vector();
    long i();
    long idx();
    bool is_alpha();
    bool is_ascii();
    bool is_bracket();
    bool is_digit();
    bool is_left_punct();
    bool is_lower();
    bool is_oov();
    bool is_punct();
    bool is_quote();
    bool is_right_punct();
    bool is_space();
    bool is_stop();
    bool is_title();
    bool is_upper();
    long lang();
    std::string lang_();
    long lemma();
    std::string lemma_();
    bool like_email();
    bool like_num();
    bool like_url();
    long lower();
    std::string lower_();
    Token nbor(long p_i = 1);
    long norm();
    std::string norm_();
    long orth();
    std::string orth_();
    long pos();
    std::string pos_();
    double prob();
    long rank();
    double sentiment();
    long shape();
    std::string shape_();
    long tag();
    std::string tag_();
    std::string text();
    std::string text_with_ws();
    std::string whitespace_();

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
