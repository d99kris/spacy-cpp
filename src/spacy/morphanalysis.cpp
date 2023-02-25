// morphanalysis.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2023 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "morphanalysis.h"

#include <map>
#include <string>
#include <vector>

#include "pyobjectptr.h"
#include "python.h"

namespace Spacy
{
  MorphAnalysis::~MorphAnalysis()
  {
  }

  std::vector<std::string> MorphAnalysis::get(const std::string& p_field) const
  {
    PyObjectPtr field(Python::get_object<std::string>(p_field));
    std::vector<PyObjectPtr> args = std::vector<PyObjectPtr>({ field });
    PyObjectPtr return_value(Python::call_method<PyObjectPtr>(m_morphanalysis, "get", args));
    return Python::get_vector<std::string>(return_value);
  }

  std::string MorphAnalysis::str() const
  {
    return Python::call_method<std::string>(m_morphanalysis, "__str__");
  }

  std::map<std::string, std::string> MorphAnalysis::to_dict() const
  {
    PyObjectPtr result = Python::call_method<PyObjectPtr>(m_morphanalysis, "to_dict");
    return Python::get_map<std::string, std::string>(result);
  }

  MorphAnalysis::MorphAnalysis(PyObjectPtr p_morphanalysis)
    : m_morphanalysis(p_morphanalysis)
  {
  }
}
