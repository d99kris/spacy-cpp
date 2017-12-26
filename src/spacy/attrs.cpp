// attrs.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "attrs.h"

#include "pyobjectptr.h"
#include "python.h"

namespace Spacy
{
  Attrs::~Attrs()
  {
  }
    
  long Attrs::IS_ALPHA() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_ALPHA");
    return val;
  }

  long Attrs::IS_ASCII() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_ASCII");
    return val;
  }

  long Attrs::IS_DIGIT() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_DIGIT");
    return val;
  }

  long Attrs::IS_LOWER() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_LOWER");
    return val;
  }

  long Attrs::IS_PUNCT() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_PUNCT");
    return val;
  }

  long Attrs::IS_SPACE() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_SPACE");
    return val;
  }

  long Attrs::IS_TITLE() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_TITLE");
    return val;
  }

  long Attrs::IS_UPPER() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_UPPER");
    return val;
  }
    
  long Attrs::LIKE_URL() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "LIKE_URL");
    return val;
  }

  long Attrs::LIKE_NUM() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "LIKE_NUM");
    return val;
  }

  long Attrs::LIKE_EMAIL() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "LIKE_EMAIL");
    return val;
  }

  long Attrs::IS_STOP() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_STOP");
    return val;
  }

  long Attrs::IS_OOV() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_OOV");
    return val;
  }
    
  long Attrs::IS_BRACKET() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_BRACKET");
    return val;
  }

  long Attrs::IS_QUOTE() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_QUOTE");
    return val;
  }

  long Attrs::IS_LEFT_PUNCT() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_LEFT_PUNCT");
    return val;
  }

  long Attrs::IS_RIGHT_PUNCT() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "IS_RIGHT_PUNCT");
    return val;
  }

  long Attrs::ID() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "ID");
    return val;
  }

  long Attrs::ORTH() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "ORTH");
    return val;
  }

  long Attrs::LOWER() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "LOWER");
    return val;
  }

  long Attrs::NORM() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "NORM");
    return val;
  }

  long Attrs::SHAPE() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "SHAPE");
    return val;
  }

  long Attrs::PREFIX() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "PREFIX");
    return val;
  }

  long Attrs::SUFFIX() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "SUFFIX");
    return val;
  }

  long Attrs::LENGTH() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "LENGTH");
    return val;
  }

  long Attrs::CLUSTER() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "CLUSTER");
    return val;
  }

  long Attrs::LEMMA() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "LEMMA");
    return val;
  }

  long Attrs::POS() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "POS");
    return val;
  }

  long Attrs::TAG() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "TAG");
    return val;
  }

  long Attrs::DEP() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "DEP");
    return val;
  }

  long Attrs::ENT_IOB() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "ENT_IOB");
    return val;
  }

  long Attrs::ENT_TYPE() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "ENT_TYPE");
    return val;
  }

  long Attrs::HEAD() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "HEAD");
    return val;
  }

  long Attrs::SENT_START() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "SENT_START");
    return val;
  }

  long Attrs::SPACY() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "SPACY");
    return val;
  }

  long Attrs::PROB() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "PROB");
    return val;
  }

  long Attrs::LANG() const
  {
    static long val = Python::get_attr_value<long>(m_attrs, "LANG");
    return val;
  }

  Attrs::Attrs(PyObjectPtr p_attrs)
    : m_attrs(p_attrs)
  {
  }
}
