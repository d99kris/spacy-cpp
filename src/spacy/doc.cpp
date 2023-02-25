// doc.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017-2020 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "doc.h"

#include <algorithm>
#include <map>
#include <vector>

#include "pyobjectptr.h"
#include "python.h"
#include "span.h"
#include "token.h"

namespace Spacy
{
  Doc::~Doc()
  {
  }

  std::map<long, long> Doc::count_by(long p_attr) const
  {
    PyObjectPtr attr(Python::get_object<long>(p_attr));
    std::vector<PyObjectPtr> args = std::vector<PyObjectPtr>({ attr });
    PyObjectPtr result = Python::call_method<PyObjectPtr>(m_doc, "count_by", args);
    return Python::get_map<long, long>(result);
  }

  std::vector<Span> Doc::ents() const
  {
    std::vector<Span> spans(Python::get_attr_vector_ctor_arg<Span, const Doc*>(m_doc, "ents", this));
    return spans;
  }

  bool Doc::has_vector() const
  {
    return Python::get_attr_value<bool>(m_doc, "has_vector");
  }

  bool Doc::is_parsed() const
  {
    return Python::get_attr_value<bool>(m_doc, "is_parsed");
  }

  bool Doc::is_tagged() const
  {
    return Python::get_attr_value<bool>(m_doc, "is_tagged");
  }

  std::vector<Span> Doc::noun_chunks() const
  {
    std::vector<Span> spans(Python::get_attr_vector_ctor_arg<Span, const Doc*>(m_doc, "noun_chunks", this));
    return spans;
  }

  double Doc::sentiment() const
  {
    return Python::get_attr_value<double>(m_doc, "sentiment");
  }

  std::vector<Span> Doc::sents() const
  {
    std::vector<Span> spans(Python::get_attr_vector_ctor_arg<Span, const Doc*>(m_doc, "sents", this));
    return spans;
  }

  double Doc::similarity(const Doc& p_doc) const
  {
    std::vector<PyObjectPtr> args = std::vector<PyObjectPtr>({ p_doc.get_ptr() });
    return Python::call_method<double>(m_doc, "similarity", args);
  }

  std::string Doc::text() const
  {
    return Python::get_attr_value<std::string>(m_doc, "text");
  }

  std::string Doc::text_with_ws() const
  {
    return Python::get_attr_value<std::string>(m_doc, "text_with_ws");
  }

  std::vector<Token> Doc::tokens() const
  {
    return Python::get_vector<Token>(m_doc);
  }

  double Doc::vector_norm() const
  {
    return Python::get_attr_value<double>(m_doc, "vector_norm");
  }

  Doc::Doc(PyObjectPtr p_doc)
    : m_doc(p_doc)
  {
  }

  PyObjectPtr Doc::get_ptr() const
  {
    return m_doc;
  }
}
