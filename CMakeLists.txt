# CMakeLists.txt
#
# URL:      https://github.com/d99kris/spacy-cpp
#
# Copyright (C) 2017-2020 Kristofer Berggren
# All rights reserved.
#
# spacy-cpp is distributed under the MIT license, see LICENSE for details.

# Project
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(spacy-cpp VERSION 1.04 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 11)
if(MSVC)
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wpedantic -Wshadow -Wpointer-arith \
                       -Wcast-qual -Wno-missing-braces -Wswitch-default -Wunreachable-code \
                       -Wundef -Wuninitialized -Wcast-align")
endif()
find_package(PythonLibs 3 REQUIRED)
find_package(PythonInterp 3 REQUIRED)

# Library
add_library(spacy SHARED
  src/spacy/attrs.cpp
  src/spacy/attrs.cpp
  src/spacy/nlp.cpp
  src/spacy/python.cpp
  src/spacy/span.cpp
  src/spacy/doc.cpp
  src/spacy/pyobjectptr.cpp
  src/spacy/spacy.cpp
  src/spacy/stringstore.cpp
  src/spacy/token.cpp
  src/spacy/vocab.cpp
  )
install(TARGETS spacy LIBRARY DESTINATION lib)
set_target_properties(spacy PROPERTIES LINK_FLAGS "-fPIC")
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(spacy ${PYTHON_LIBRARIES})

# Headers
install(FILES
  src/spacy/attrs.h
  src/spacy/nlp.h
  src/spacy/python.h
  src/spacy/span.h
  src/spacy/doc.h
  src/spacy/pyobjectptr.h
  src/spacy/spacy
  src/spacy/spacy.h
  src/spacy/stringstore.h
  src/spacy/token.h
  src/spacy/vocab.h
  DESTINATION include/spacy)

# Tests
enable_testing()
include_directories("src")
set(LIB_HEADERS "src/spacy/spacy")
set(TEST_HEADERS "tests/unittest.h")

function(add_spacy_test target)

  add_executable(test_link_${target} tests/test_${target}.cpp)
  target_link_libraries(test_link_${target} spacy)
  add_test(test_link_${target} "${PROJECT_BINARY_DIR}/test_link_${target}")

  add_executable(test_header_${target} tests/test_${target}.cpp)
  target_compile_definitions(test_header_${target} PRIVATE SPACY_HEADER_ONLY=1)
  target_link_libraries(test_header_${target} ${PYTHON_LIBRARIES})
  add_test(test_header_${target} "${PROJECT_BINARY_DIR}/test_header_${target}")
  
endfunction()

add_spacy_test(spacy)
add_spacy_test(attrs)
add_spacy_test(nlp)
add_spacy_test(doc)
add_spacy_test(vocab)
add_spacy_test(stringstore)
add_spacy_test(span)
add_spacy_test(token)
