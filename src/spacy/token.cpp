// token.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017-2023 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "token.h"

#include <string>
#include <vector>

#include "morphanalysis.h"
#include "pyobjectptr.h"
#include "python.h"

namespace Spacy
{
  Token::~Token()
  {
  }

  bool Token::check_flag(long p_attr) const
  {
    std::vector<PyObjectPtr> args = std::vector<PyObjectPtr>({ Python::get_object<long>(p_attr) });
    return Python::call_method<bool>(m_token, "check_flag", args);
  }

  std::vector<Token> Token::children() const
  {
    return Python::get_attr_vector<Token>(m_token, "children");
  }

  long Token::cluster() const
  {
    return Python::get_attr_value<long>(m_token, "cluster");
  }

  long Token::dep() const
  {
    return Python::get_attr_value<long>(m_token, "dep");
  }

  std::string Token::dep_() const
  {
    return Python::get_attr_value<std::string>(m_token, "dep_");
  }

  std::string Token::ent_iob_() const
  {
    return Python::get_attr_value<std::string>(m_token, "ent_iob_");
  }

  bool Token::has_vector() const
  {
    return Python::get_attr_value<bool>(m_token, "has_vector");
  }

  Token Token::head() const
  {
    return Python::get_attr_obj<Token>(m_token, "head");
  }

  long Token::i() const
  {
    return Python::get_attr_value<long>(m_token, "i");
  }

  long Token::idx() const
  {
    return Python::get_attr_value<long>(m_token, "idx");
  }

  bool Token::is_alpha() const
  {
    return Python::get_attr_value<bool>(m_token, "is_alpha");
  }

  bool Token::is_ascii() const
  {
    return Python::get_attr_value<bool>(m_token, "is_ascii");
  }

  bool Token::is_bracket() const
  {
    return Python::get_attr_value<bool>(m_token, "is_bracket");
  }

  bool Token::is_digit() const
  {
    return Python::get_attr_value<bool>(m_token, "is_digit");
  }

  bool Token::is_left_punct() const
  {
    return Python::get_attr_value<bool>(m_token, "is_left_punct");
  }

  bool Token::is_lower() const
  {
    return Python::get_attr_value<bool>(m_token, "is_lower");
  }

  bool Token::is_oov() const
  {
    return Python::get_attr_value<bool>(m_token, "is_oov");
  }

  bool Token::is_punct() const
  {
    return Python::get_attr_value<bool>(m_token, "is_punct");
  }

  bool Token::is_quote() const
  {
    return Python::get_attr_value<bool>(m_token, "is_quote");
  }

  bool Token::is_right_punct() const
  {
    return Python::get_attr_value<bool>(m_token, "is_right_punct");
  }

  bool Token::is_space() const
  {
    return Python::get_attr_value<bool>(m_token, "is_space");
  }

  bool Token::is_stop() const
  {
    return Python::get_attr_value<bool>(m_token, "is_stop");
  }

  bool Token::is_title() const
  {
    return Python::get_attr_value<bool>(m_token, "is_title");
  }

  bool Token::is_upper() const
  {
    return Python::get_attr_value<bool>(m_token, "is_upper");
  }

  long Token::lang() const
  {
    return Python::get_attr_value<long>(m_token, "lang");
  }

  std::string Token::lang_() const
  {
    return Python::get_attr_value<std::string>(m_token, "lang_");
  }

  long Token::lemma() const
  {
    return Python::get_attr_value<long>(m_token, "lemma");
  }

  std::string Token::lemma_() const
  {
    return Python::get_attr_value<std::string>(m_token, "lemma_");
  }

  bool Token::like_email() const
  {
    return Python::get_attr_value<bool>(m_token, "like_email");
  }

  bool Token::like_num() const
  {
    return Python::get_attr_value<bool>(m_token, "like_num");
  }

  bool Token::like_url() const
  {
    return Python::get_attr_value<bool>(m_token, "like_url");
  }

  long Token::lower() const
  {
    return Python::get_attr_value<long>(m_token, "lower");
  }

  std::string Token::lower_() const
  {
    return Python::get_attr_value<std::string>(m_token, "lower_");
  }

  MorphAnalysis Token::morph() const
  {
    return Python::get_attr_obj<MorphAnalysis>(m_token, "morph");
  }

  Token Token::nbor(long p_i /* = 1 */) const
  {
    std::vector<PyObjectPtr> args = std::vector<PyObjectPtr>({ Python::get_object<long>(p_i) });
    return Token(Python::call_method<PyObjectPtr>(m_token, "nbor", args));
  }

  long Token::norm() const
  {
    return Python::get_attr_value<long>(m_token, "norm");
  }

  std::string Token::norm_() const
  {
    return Python::get_attr_value<std::string>(m_token, "norm_");
  }

  long Token::orth() const
  {
    return Python::get_attr_value<long>(m_token, "orth");
  }

  std::string Token::orth_() const
  {
    return Python::get_attr_value<std::string>(m_token, "orth_");
  }

  long Token::pos() const
  {
    return Python::get_attr_value<long>(m_token, "pos");
  }

  std::string Token::pos_() const
  {
    return Python::get_attr_value<std::string>(m_token, "pos_");
  }

  double Token::prob() const
  {
    return Python::get_attr_value<double>(m_token, "prob");
  }

  double Token::rank() const
  {
    return Python::get_attr_value<double>(m_token, "rank");
  }

  double Token::sentiment() const
  {
    return Python::get_attr_value<double>(m_token, "sentiment");
  }

  long Token::shape() const
  {
    return Python::get_attr_value<long>(m_token, "shape");
  }

  std::string Token::shape_() const
  {
    return Python::get_attr_value<std::string>(m_token, "shape_");
  }

  long Token::tag() const
  {
    return Python::get_attr_value<long>(m_token, "tag");
  }

  std::string Token::tag_() const
  {
    return Python::get_attr_value<std::string>(m_token, "tag_");
  }

  std::string Token::text() const
  {
    return Python::get_attr_value<std::string>(m_token, "text");
  }

  std::string Token::text_with_ws() const
  {
    return Python::get_attr_value<std::string>(m_token, "text_with_ws");
  }

  std::string Token::whitespace_() const
  {
    return Python::get_attr_value<std::string>(m_token, "whitespace_");
  }

  Token::Token(PyObjectPtr p_token)
    : m_token(p_token)
  {
  }

  PyObjectPtr Token::get_ptr() const
  {
    return m_token;
  }
}
