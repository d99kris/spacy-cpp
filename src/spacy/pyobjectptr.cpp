// pyobjectptr.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "pyobjectptr.h"

#include <memory>
#include <Python.h>

namespace Spacy
{
  PyObjectPtr::PyObjectPtr(PyObject* p_obj /* = nullptr */)
    : std::shared_ptr<PyObject>(p_obj, Deleter())
  {
  }

  void PyObjectPtr::reset(PyObject* p_obj /* = nullptr */)
  {
    std::shared_ptr<PyObject>::reset(p_obj, Deleter());
  }

  void PyObjectPtr::Deleter::operator()(PyObject* p_obj) const
  {
    if (p_obj)
    {
      assert(p_obj->ob_refcnt > 0);
      Py_DECREF(p_obj);
    }
  }
}
