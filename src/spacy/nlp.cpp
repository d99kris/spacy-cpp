// nlp.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "nlp.h"

#include <string>

#include "doc.h"
#include "pyobjectptr.h"
#include "python.h"
#include "vocab.h"

namespace Spacy
{
  Nlp::~Nlp()
  {
  }

  Doc Nlp::parse(const std::string& p_text) const
  {
    PyObjectPtr text(Python::get_object<std::string>(p_text));
    std::vector<PyObjectPtr> args = std::vector<PyObjectPtr>({ text });
    PyObjectPtr doc(Python::call_method<PyObjectPtr>(m_nlp, args));
    return doc;
  }

  Vocab Nlp::vocab() const
  {
    return Vocab(PyObjectPtr(Python::get_attr_value<PyObjectPtr>(m_nlp, "vocab")));
  }

  Nlp::Nlp(PyObjectPtr p_nlp)
    : m_nlp(p_nlp)
  {
  }
}
