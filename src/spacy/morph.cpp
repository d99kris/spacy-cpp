// morph.cpp
//
// URL:      https://github.com/Alfredlang1989/spacy-cpp
//
// Copyright (C) 2022 Alfred Lang
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include "morph.h"

#include <string>

#include "python.h"
#include "stringstore.h"
#include <iostream>


namespace Spacy
{
  Morph::~Morph()
  {
  }

  Morph::Morph()
  {
  }


  Morph::Morph(PyObjectPtr p_morph)
    : m_morph(p_morph)
  {
  }


 std::string Morph::to_string() const
  {
	return Python::call_method<std::string>(m_morph, "__str__");
  }

std::map<std::string,std::string> Morph::to_dict(){


    PyObjectPtr result = Python::call_method<PyObjectPtr>(m_morph, "to_dict");
    return Python::get_map<std::string, std::string>(result);

}

std::string Morph::get(std::string feat)
  {
	//Pythons "get" seems not working here.
	//i spend a lot of time to check why.. 
	//Workaround : to_dict, and fetsch the value
	  std::map<std::string,std::string> map = this->to_dict();
	  for (auto val : map){
	      if( val.first == feat){
		      return val.second;
	      }
	  }
	  //return empty string. Same behavior as in python..
	  return "";

  }

  

}
