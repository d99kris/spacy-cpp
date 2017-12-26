// token.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "token.h"

#include <string>
#include <vector>

#include "pyobjectptr.h"
#include "python.h"

namespace Spacy
{
  Token::~Token()
  {
  }

  bool Token::check_flag(long p_attr)
  {
    std::vector<PyObjectPtr> args = std::vector<PyObjectPtr>({Python::get_object<long>(p_attr)});
    return Python::call_method<bool>(m_token, "check_flag", args);
  }

  std::vector<Token> Token::children()
  {
    return Python::get_attr_vector<Token>(m_token, "children");
  }

  long Token::cluster()
  {
    return Python::get_attr_value<long>(m_token, "cluster");
  }
    
  long Token::dep()
  {
    return Python::get_attr_value<long>(m_token, "dep");
  }

  std::string Token::dep_()
  {
    return Python::get_attr_value<std::string>(m_token, "dep_");
  }

  std::string Token::ent_iob_()
  {
    return Python::get_attr_value<std::string>(m_token, "ent_iob_");
  }

  bool Token::has_vector()
  {
    return Python::get_attr_value<bool>(m_token, "has_vector");
  }

  long Token::i()
  {
    return Python::get_attr_value<long>(m_token, "i");
  }

  long Token::idx()
  {
    return Python::get_attr_value<long>(m_token, "idx");
  }

  bool Token::is_alpha()
  {
    return Python::get_attr_value<bool>(m_token, "is_alpha");
  }

  bool Token::is_ascii()
  {
    return Python::get_attr_value<bool>(m_token, "is_ascii");
  }

  bool Token::is_bracket()
  {
    return Python::get_attr_value<bool>(m_token, "is_bracket");
  }

  bool Token::is_digit()
  {
    return Python::get_attr_value<bool>(m_token, "is_digit");
  }

  bool Token::is_left_punct()
  {
    return Python::get_attr_value<bool>(m_token, "is_left_punct");
  }

  bool Token::is_lower()
  {
    return Python::get_attr_value<bool>(m_token, "is_lower");
  }

  bool Token::is_oov()
  {
    return Python::get_attr_value<bool>(m_token, "is_oov");
  }

  bool Token::is_punct()
  {
    return Python::get_attr_value<bool>(m_token, "is_punct");
  }

  bool Token::is_quote()
  {
    return Python::get_attr_value<bool>(m_token, "is_quote");
  }

  bool Token::is_right_punct()
  {
    return Python::get_attr_value<bool>(m_token, "is_right_punct");
  }

  bool Token::is_space()
  {
    return Python::get_attr_value<bool>(m_token, "is_space");
  }

  bool Token::is_stop()
  {
    return Python::get_attr_value<bool>(m_token, "is_stop");
  }

  bool Token::is_title()
  {
    return Python::get_attr_value<bool>(m_token, "is_title");
  }

  bool Token::is_upper()
  {
    return Python::get_attr_value<bool>(m_token, "is_upper");
  }

  long Token::lang()
  {
    return Python::get_attr_value<long>(m_token, "lang");
  }
      
  std::string Token::lang_()
  {
    return Python::get_attr_value<std::string>(m_token, "lang_");
  }
 
  long Token::lemma()
  {
    return Python::get_attr_value<long>(m_token, "lemma");
  }
    
  std::string Token::lemma_()
  {
    return Python::get_attr_value<std::string>(m_token, "lemma_");
  }
 
  bool Token::like_email()
  {
    return Python::get_attr_value<bool>(m_token, "like_email");
  }

  bool Token::like_num()
  {
    return Python::get_attr_value<bool>(m_token, "like_num");
  }

  bool Token::like_url()
  {
    return Python::get_attr_value<bool>(m_token, "like_url");
  }

  long Token::lower()
  {
    return Python::get_attr_value<long>(m_token, "lower");
  }
    
  std::string Token::lower_()
  {
    return Python::get_attr_value<std::string>(m_token, "lower_");
  }
 
  Token Token::nbor(long p_i /* = 1 */)
  {
    std::vector<PyObjectPtr> args = std::vector<PyObjectPtr>({Python::get_object<long>(p_i)});
    return Token(Python::call_method<PyObjectPtr>(m_token, "nbor", args));
  }

  long Token::norm()
  {
    return Python::get_attr_value<long>(m_token, "norm");
  }
    
  std::string Token::norm_()
  {
    return Python::get_attr_value<std::string>(m_token, "norm_");
  }
 
  long Token::orth()
  {
    return Python::get_attr_value<long>(m_token, "orth");
  }

  std::string Token::orth_()
  {
    return Python::get_attr_value<std::string>(m_token, "orth_");
  }

  long Token::pos()
  {
    return Python::get_attr_value<long>(m_token, "pos");
  }
      
  std::string Token::pos_()
  {
    return Python::get_attr_value<std::string>(m_token, "pos_");
  }
 
  double Token::prob()
  {
    return Python::get_attr_value<double>(m_token, "prob");
  }

  long Token::rank()
  {
    return Python::get_attr_value<long>(m_token, "rank");
  }
    
  double Token::sentiment()
  {
    return Python::get_attr_value<double>(m_token, "sentiment");
  }

  long Token::shape()
  {
    return Python::get_attr_value<long>(m_token, "shape");
  }
    
  std::string Token::shape_()
  {
    return Python::get_attr_value<std::string>(m_token, "shape_");
  }
 
  long Token::tag()
  {
    return Python::get_attr_value<long>(m_token, "tag");
  }
      
  std::string Token::tag_()
  {
    return Python::get_attr_value<std::string>(m_token, "tag_");
  }
 
  std::string Token::text()
  {
    return Python::get_attr_value<std::string>(m_token, "text");
  }
    
  std::string Token::text_with_ws()
  {
    return Python::get_attr_value<std::string>(m_token, "text_with_ws");
  }

  std::string Token::whitespace_()
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
