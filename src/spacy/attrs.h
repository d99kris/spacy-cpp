// attrs.h
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#pragma once

#include "pyobjectptr.h"

namespace Spacy
{
  class Spacy;

  class Attrs
  {
    friend Spacy;

  public:
    virtual ~Attrs();

    long IS_ALPHA() const;
    long IS_ASCII() const;
    long IS_DIGIT() const;
    long IS_LOWER() const;
    long IS_PUNCT() const;
    long IS_SPACE() const;
    long IS_TITLE() const;
    long IS_UPPER() const;
    long LIKE_URL() const;
    long LIKE_NUM() const;
    long LIKE_EMAIL() const;
    long IS_STOP() const;
    long IS_OOV() const;
    long IS_BRACKET() const;
    long IS_QUOTE() const;
    long IS_LEFT_PUNCT() const;
    long IS_RIGHT_PUNCT() const;
    long ID() const;
    long ORTH() const;
    long LOWER() const;
    long NORM() const;
    long SHAPE() const;
    long PREFIX() const;
    long SUFFIX() const;
    long LENGTH() const;
    long CLUSTER() const;
    long LEMMA() const;
    long POS() const;
    long TAG() const;
    long DEP() const;
    long ENT_IOB() const;
    long ENT_TYPE() const;
    long HEAD() const;
    long SENT_START() const;
    long SPACY() const;
    long PROB() const;
    long LANG() const;

  private:
    explicit Attrs(PyObjectPtr p_attrs);

  private:
    PyObjectPtr m_attrs;
  };
}

#ifdef SPACY_HEADER_ONLY
#include "attrs.cpp"
#endif
