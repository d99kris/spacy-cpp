// python.h
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#pragma once

#include <map>
#include <memory>
#include <vector>
#include <Python.h>

#include "pyobjectptr.h"

namespace Spacy
{
  class Python
  {
  public:
    static std::shared_ptr<Python> get_instance();
    virtual ~Python();

    template <typename T>
    static T call_method(PyObjectPtr p_method,
                         const std::vector<PyObjectPtr>& p_args = std::vector<PyObjectPtr>())
    {
      assert(PyCallable_Check(p_method.get()));
      PyObjectPtr args(PyTuple_New(p_args.size()));
      PyObjectPtr named_args(PyDict_New());
      for (size_t i = 0; i < p_args.size(); ++i)
      {
        Py_INCREF(p_args.at(i).get());
        PyTuple_SetItem(args.get(), i, p_args.at(i).get());
      }
      PyObjectPtr return_value(PyObject_Call(p_method.get(), args.get(), named_args.get()));
      return get_value<T>(return_value);
    }

    template <typename T>
    static T call_method(PyObjectPtr p_obj, const std::string& p_method,
                         const std::vector<PyObjectPtr>& p_args = std::vector<PyObjectPtr>())
    {
      assert(PyObject_HasAttrString(p_obj.get(), p_method.c_str()));
      PyObjectPtr method(PyObject_GetAttrString(p_obj.get(), p_method.c_str()));
      return call_method<T>(method, p_args);
    }

    template <typename T>
    static T get_dict_value(PyObjectPtr p_obj, PyObjectPtr p_key)
    {
      assert(PyDict_Check(p_obj.get()));
      PyObjectPtr return_value(PyDict_GetItem(p_obj.get(), p_key.get()));
      return get_value<T>(return_value);
    }

    template <typename T>
    static T get_attr_value(PyObjectPtr p_obj, const std::string& p_attr)
    {
      assert(PyObject_HasAttrString(p_obj.get(), p_attr.c_str()));
      PyObjectPtr attr(PyObject_GetAttrString(p_obj.get(), p_attr.c_str()));
      return get_value<T>(attr);
    }

    template <typename T>
    static std::vector<T> get_attr_vector(PyObjectPtr p_obj, const std::string& p_attr)
    {
      assert(PyObject_HasAttrString(p_obj.get(), p_attr.c_str()));
      PyObjectPtr attr(PyObject_GetAttrString(p_obj.get(), p_attr.c_str()));
      return get_vector<T>(attr);
    }

    template <typename T, typename U>
    static std::map<T, U> get_map(PyObjectPtr p_obj)
    {
      assert(PyDict_Check(p_obj.get()));
      std::map<T, U> map;
      PyObject *key;
      PyObject *value;
      Py_ssize_t pos = 0;
      while (PyDict_Next(p_obj.get(), &pos, &key, &value))
      {
        Py_INCREF(key);
        Py_INCREF(value);
        map[get_value<T>(PyObjectPtr(key))] = get_value<U>(PyObjectPtr(value));
      }
      return map;
    }

    template <typename T>
    static PyObjectPtr get_object(T p_val)
    {
      return Convert<T>::get_object(p_val);
    }

    template <typename T>
    static T get_value(PyObjectPtr p_obj)
    {
      return Convert<T>::get_value(p_obj);
    }

    template <typename T>
    static std::vector<T> get_vector(PyObjectPtr p_obj)
    {
      assert(PySequence_Check(p_obj.get()) || PyIter_Check(p_obj.get()));
      PyObjectPtr list(PySequence_List(p_obj.get()));
      Py_ssize_t size = PySequence_Size(list.get());
      std::vector<T> items;
      for (Py_ssize_t i = 0; i < size; ++i)
      {
        items.push_back(T(PyObjectPtr(PySequence_GetItem(list.get(), i))));
      }
      return items;
    }

    static PyObjectPtr import(const std::string& p_name)
    {
      PyObjectPtr name(Python::get_object<std::string>(p_name));
      return PyObjectPtr(PyImport_Import(name.get()));
    }

  private:
    Python();

  private:
    template <typename T>
    class Convert
    {
    public:
      static T get_value(PyObjectPtr p_obj)
      {
        (void)(p_obj);
        assert(0);
      }

      static PyObjectPtr get_object(T p_val)
      {
        (void)(p_val);
        assert(0);
      }
  };
    
  private:
    std::shared_ptr<char*> m_argv;
  };

  template <>
  bool Python::Convert<bool>::get_value(PyObjectPtr p_obj);
  template <>
  double Python::Convert<double>::get_value(PyObjectPtr p_obj);
  template <>
  long Python::Convert<long>::get_value(PyObjectPtr p_obj);
  template <>
  PyObjectPtr Python::Convert<PyObjectPtr>::get_value(PyObjectPtr p_obj);
  template <>
  std::string Python::Convert<std::string>::get_value(PyObjectPtr p_obj);
  template <>
  PyObjectPtr Python::Convert<bool>::get_object(bool p_val);
  template <>
  PyObjectPtr Python::Convert<double>::get_object(double p_val);
  template <>
  PyObjectPtr Python::Convert<long>::get_object(long p_val);
  template <>
  PyObjectPtr Python::Convert<PyObjectPtr>::get_object(PyObjectPtr p_val);
  template <>
  PyObjectPtr Python::Convert<std::string>::get_object(std::string p_val);
}

#ifdef SPACY_HEADER_ONLY
#include "python.cpp"
#endif
