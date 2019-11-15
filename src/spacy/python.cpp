// python.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "python.h"

#include <memory>
#include <Python.h>

namespace Spacy
{
  std::shared_ptr<Python> Python::get_instance()
  {
    static std::weak_ptr<Python> s_instance;
    std::shared_ptr<Python> instance;
    if (s_instance.expired())
    {
      instance.reset(new Python());
      s_instance = instance;
    }
    return instance;
  }

  Python::~Python()
  {
    Py_Finalize();
  }

  Python::Python()
    : m_argv(std::make_shared<char*>(nullptr))
  {
    Py_Initialize();
    PySys_SetArgv(0, m_argv.get());
  }

  template <>
  bool Python::Convert<bool>::get_value(PyObjectPtr p_obj)
  {
    assert(PyBool_Check(p_obj.get()));
    return PyObject_IsTrue(p_obj.get());
  }

  template <>
  double Python::Convert<double>::get_value(PyObjectPtr p_obj)
  {
    assert(Custom_PyFloat_Check(p_obj));
    return PyFloat_AsDouble(p_obj.get());
  }

  template <>
  long Python::Convert<long>::get_value(PyObjectPtr p_obj)
  {
    assert(PyLong_Check(p_obj.get()) || PyInt_Check(p_obj.get()));
    return PyLong_AsLong(p_obj.get());
  }

  template <>
  PyObjectPtr Python::Convert<PyObjectPtr>::get_value(PyObjectPtr p_obj)
  {
    return p_obj;
  }
  
  template <>
  std::string Python::Convert<std::string>::get_value(PyObjectPtr p_obj)
  {
    if (PyUnicode_Check(p_obj.get()))
    {
      PyObjectPtr utf8(PyUnicode_AsUTF8String(p_obj.get()));
      return PyBytes_AsString(utf8.get());
    }
    else if (PyBytes_Check(p_obj.get()))
    {
      return std::string(PyBytes_AsString(p_obj.get()), PyBytes_Size(p_obj.get()));
    }
    else
    {
      assert(0);
    }
  }
    
  template <>
  PyObjectPtr Python::Convert<bool>::get_object(bool p_val)
  {
    return PyObjectPtr(PyBool_FromLong(p_val));
  }

  template <>
  PyObjectPtr Python::Convert<double>::get_object(double p_val)
  {
    return PyObjectPtr(PyFloat_FromDouble(p_val));
  }

  template <>
  PyObjectPtr Python::Convert<long>::get_object(long p_val)
  {
    return PyObjectPtr(PyInt_FromLong(p_val));
  }

  template <>
  PyObjectPtr Python::Convert<PyObjectPtr>::get_object(PyObjectPtr p_val)
  {
    return p_val;
  }

  template <>
  PyObjectPtr Python::Convert<std::string>::get_object(std::string p_val)
  {
    return PyObjectPtr(PyUnicode_FromStringAndSize(p_val.c_str(), p_val.size()));
  }

  bool Python::Custom_PyFloat_Check(PyObjectPtr p_obj)
  {
    if (PyFloat_Check(p_obj.get()))
    {
      return true;
    }
    else
    {
      PyObjectPtr __float__(PyObject_HasAttrString(p_obj.get(), "__float__") ?
                            PyObject_GetAttrString(p_obj.get(), "__float__") : nullptr);
      return (__float__.get() != nullptr) ? PyCallable_Check(__float__.get()) : false;
    }
  }
}
