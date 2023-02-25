// stringstore.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "stringstore.h"

#include <string>

#include "python.h"

namespace Spacy
{
  StringStore::~StringStore()
  {
  }

  long StringStore::add(const std::string& p_str) const
  {
    PyObjectPtr str(Python::get_object<std::string>(p_str));
    std::vector<PyObjectPtr> args = std::vector<PyObjectPtr>({ str });
    PyObjectPtr return_value(Python::call_method<PyObjectPtr>(m_stringstore, "add", args));
    return Python::get_value<long>(return_value);
  }

  StringStore::StringStore(PyObjectPtr p_stringstore)
    : m_stringstore(p_stringstore)
  {
  }
}
