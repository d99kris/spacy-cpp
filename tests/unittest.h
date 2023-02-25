// unittest.h
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#pragma once

#ifndef _MSC_VER
#include <unistd.h>
#else
#include <io.h>
#endif

#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>

namespace unittest
{
  namespace detail
  {
    inline std::string FileName(const std::string& pPath)
    {
      const std::size_t slash = pPath.rfind("/");
      std::string name = (slash != std::string::npos) ? pPath.substr(slash + 1) : pPath;
      return name;
    }
  }

#define ExpectEqual(t, a, b) ExpectEqualFun<t>(a, b, #a, #b, __FILE__, __LINE__);

  template<typename T>
  inline void ExpectEqualFun(T pTest, T pRef, const std::string& testName, const std::string& refName,
                             const std::string& filePath, int lineNo)
  {
    if (pTest != pRef)
    {
      std::stringstream ss;
      ss << detail::FileName(filePath) << ":" << std::to_string(lineNo) << " ExpectEqual failed: " << testName <<
      " != " << refName << std::endl;
      ss << testName << " = '" << pTest << "'" << std::endl;
      ss << refName << " = '" << pRef << "'" << std::endl;

      throw std::runtime_error(ss.str());
    }
  }

#define ExpectTrue(a) ExpectTrueFun(a, #a, __FILE__, __LINE__);

  inline void ExpectTrueFun(bool pTest, const std::string& testName, const std::string& filePath, int lineNo)
  {
    if (!pTest)
    {
      std::stringstream ss;
      ss << detail::FileName(filePath) << ":" << std::to_string(lineNo) << " ExpectTrue failed: " << testName <<
      " == false" << std::endl;

      throw std::runtime_error(ss.str());
    }
  }
}
