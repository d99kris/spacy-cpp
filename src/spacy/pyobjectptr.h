// pyobjectptr.h
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#pragma once

#include <memory>
#include <Python.h>

namespace Spacy
{
  class PyObjectPtr : public std::shared_ptr<PyObject>
  {
  public:
    explicit PyObjectPtr(PyObject* p_obj = nullptr);
    void reset(PyObject* p_obj = nullptr);

  private:
    struct Deleter
    {
      void operator()(PyObject* p_obj) const;
    };
  };
}

#ifdef SPACY_HEADER_ONLY
#include "pyobjectptr.cpp"
#endif
