// span.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "span.h"

#include <string>
#include <vector>

#include "pyobjectptr.h"
#include "python.h"
#include "token.h"

namespace Spacy
{
  Span::~Span()
  {
  }

  Doc* Span::doc()
  {
    return m_parent;
  }

  long Span::label()
  {
    return Python::get_attr_value<long>(m_span, "label");
  }
    
  std::string Span::label_()
  {
    return Python::get_attr_value<std::string>(m_span, "label_");
  }

  std::string Span::lemma_()
  {
    return Python::get_attr_value<std::string>(m_span, "lemma_");
  }

  std::string Span::orth_()
  {
    return Python::get_attr_value<std::string>(m_span, "orth_");
  }

  Token Span::root()
  {
    return Token(Python::get_attr_value<PyObjectPtr>(m_span, "root"));
  }

  double Span::sentiment()
  {
    return Python::get_attr_value<double>(m_span, "sentiment");
  }

  std::string Span::text()
  {
    return Python::get_attr_value<std::string>(m_span, "text");
  }

  std::string Span::text_with_ws()
  {
    return Python::get_attr_value<std::string>(m_span, "text_with_ws");
  }

  std::vector<Token> Span::tokens()
  {
    return Python::get_vector<Token>(m_span);
  }

  double Span::vector_norm()
  {
    return Python::get_attr_value<double>(m_span, "vector_norm");
  }

  Span::Span(PyObjectPtr p_span, Doc* p_parent /* = nullptr */)
    : m_span(p_span)
    , m_parent(p_parent)
  {
  }

  void Span::set_parent(Doc* p_parent)
  {
    m_parent = p_parent;
  }
}
