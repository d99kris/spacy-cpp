// doc.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
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

  std::map<long, long> Doc::count_by(long p_attr)
  {
    PyObjectPtr attr(Python::get_object<long>(p_attr));
    std::vector<PyObjectPtr> args = std::vector<PyObjectPtr>({attr});
    PyObjectPtr result = Python::call_method<PyObjectPtr>(m_doc, "count_by", args);
    return Python::get_map<long, long>(result);
  }

  //Span Doc::ents()
  //{
  //  return Span(Python::get_attr_value<PyObjectPtr>(m_doc, "ents"), this);
  //}
  std::vector<Span> Doc::ents()
  {
    std::vector<Span> spans(Python::get_attr_vector<Span>(m_doc, "ents"));
    std::for_each(spans.begin(), spans.end(), std::bind2nd(std::mem_fun_ref(&Span::set_parent), this));
    return spans;
  }

  bool Doc::has_vector()
  {
    return Python::get_attr_value<bool>(m_doc, "has_vector");
  }

  bool Doc::is_parsed()
  {
    return Python::get_attr_value<bool>(m_doc, "is_parsed");
  }

  bool Doc::is_tagged()
  {
    return Python::get_attr_value<bool>(m_doc, "is_tagged");
  }

  std::vector<Span> Doc::noun_chunks()
  {
    std::vector<Span> spans(Python::get_attr_vector<Span>(m_doc, "noun_chunks"));
    std::for_each(spans.begin(), spans.end(), std::bind2nd(std::mem_fun_ref(&Span::set_parent), this));
    return spans;
  }

  double Doc::sentiment()
  {
    return Python::get_attr_value<double>(m_doc, "sentiment");
  }

  std::vector<Span> Doc::sents()
  {
    std::vector<Span> spans(Python::get_attr_vector<Span>(m_doc, "sents"));
    std::for_each(spans.begin(), spans.end(), std::bind2nd(std::mem_fun_ref(&Span::set_parent), this));
    return spans;
  }

  double Doc::similarity(const Doc& p_doc)
  {
    std::vector<PyObjectPtr> args = std::vector<PyObjectPtr>({p_doc.get_ptr()});
    return Python::call_method<double>(m_doc, "similarity", args);
  }

  std::string Doc::text()
  {
    return Python::get_attr_value<std::string>(m_doc, "text");
  }

  std::string Doc::text_with_ws()
  {
    return Python::get_attr_value<std::string>(m_doc, "text_with_ws");
  }

  std::vector<Token> Doc::tokens()
  {
    return Python::get_vector<Token>(m_doc);
  }

  double Doc::vector_norm()
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
