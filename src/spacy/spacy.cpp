// spacy.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017-2026 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "spacy.h"

#include <memory>
#include <stdexcept>
#include <string>

#include "attrs.h"
#include "nlp.h"
#include "pyobjectptr.h"
#include "python.h"

namespace Spacy
{
  Spacy::Spacy()
    : m_python(Python::get_instance())
    , m_spacy(Python::import("spacy"))
  {
    if (m_spacy.get() == nullptr)
    {
      const bool not_found = PyErr_ExceptionMatches(PyExc_ImportError);
      const std::string error = Python::get_error();
      if (!not_found)
      {
        throw std::runtime_error("Failed to import spacy (" + error + ")");
      }

#ifdef PYTHON_EXECUTABLE
      const std::string interpreter = PYTHON_EXECUTABLE;
#else
      const std::string interpreter = "python3";
#endif
      throw std::runtime_error("No module named spacy (" + error + "). "
                               "Try: " + interpreter + " -m pip install -U spacy");
    }
  }

  Spacy::~Spacy()
  {
  }

  Nlp Spacy::load(const std::string& p_model) const
  {
    PyObjectPtr model(Python::get_object<std::string>(p_model));
    std::vector<PyObjectPtr> args = std::vector<PyObjectPtr>({ model });
    PyObjectPtr nlp(Python::call_method<PyObjectPtr>(m_spacy, "load", args));
    if (nlp.get() == nullptr)
    {
      // spacy raises OSError when model is not found, any other error is a load failure
      const bool not_found = PyErr_ExceptionMatches(PyExc_OSError);
      const std::string error = Python::get_error();
      if (!not_found)
      {
        throw std::runtime_error("Failed to load model '" + p_model + "' (" + error + ")");
      }

#ifdef PYTHON_EXECUTABLE
      const std::string interpreter = PYTHON_EXECUTABLE;
#else
      const std::string interpreter = "python3";
#endif
      throw std::runtime_error("Can't find model '" + p_model + "' (" + error + "). "
                               "Try: " + interpreter + " -m spacy download " + p_model);
    }
    return nlp;
  }

  const Attrs& Spacy::attrs()
  {
    if (!m_attrs)
    {
      m_attrs.reset(new Attrs(Python::get_attr_value<PyObjectPtr>(m_spacy, "attrs")));
    }
    return *m_attrs;
  }
}
