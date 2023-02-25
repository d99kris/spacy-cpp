# CMakeLists.txt
#
# URL:      https://github.com/d99kris/spacy-cpp
#
# Copyright (C) 2017-2023 Kristofer Berggren
# All rights reserved.
#
# spacy-cpp is distributed under the MIT license, see LICENSE for details.

# Project
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(spacy-cpp VERSION 1.07 LANGUAGES CXX)
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

# Ccache
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  message(STATUS "Found ccache")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

# Library
add_library(spacy SHARED
  src/spacy/attrs.cpp
  src/spacy/attrs.cpp
  src/spacy/morphanalysis.cpp
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
target_include_directories(spacy PUBLIC ${PYTHON_INCLUDE_DIRS}
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/src>")
target_link_libraries(spacy ${PYTHON_LIBRARIES})

add_library(spacy-hdr INTERFACE)
target_include_directories(spacy-hdr INTERFACE src ${PYTHON_INCLUDE_DIRS})

# Headers
install(FILES
  src/spacy/attrs.h
  src/spacy/morphanalysis.h
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

# Uninstall
add_custom_target(uninstall
  COMMAND "${CMAKE_COMMAND}" -E remove "${CMAKE_INSTALL_PREFIX}/lib/libspacy${CMAKE_SHARED_LIBRARY_SUFFIX}"
  COMMAND "${CMAKE_COMMAND}" -E remove_directory "${CMAKE_INSTALL_PREFIX}/include/spacy"
)

# Tests
option(SPACYCPP_BUILD_TESTS "Build tests" OFF)
message(STATUS "Build tests: ${SPACYCPP_BUILD_TESTS}")
if(SPACYCPP_BUILD_TESTS)

  # Tests init
  enable_testing()
  include_directories("src")
  set(LIB_HEADERS "src/spacy/spacy")
  set(TEST_HEADERS "tests/unittest.h")

  macro(add_spacy_test target)
    add_executable(test_link_${target} tests/test_${target}.cpp)
    target_link_libraries(test_link_${target} spacy)
    add_test(test_link_${target} "${PROJECT_BINARY_DIR}/test_link_${target}")

    add_executable(test_header_${target} tests/test_${target}.cpp)
    target_compile_definitions(test_header_${target} PRIVATE SPACY_HEADER_ONLY=1)
    target_link_libraries(test_header_${target} ${PYTHON_LIBRARIES})
    target_include_directories(test_header_${target} PRIVATE ${PYTHON_INCLUDE_DIRS})
    add_test(test_header_${target} "${PROJECT_BINARY_DIR}/test_header_${target}")
  endmacro()

  add_spacy_test(spacy)
  add_spacy_test(attrs)
  add_spacy_test(morphanalysis)
  add_spacy_test(nlp)
  add_spacy_test(doc)
  add_spacy_test(vocab)
  add_spacy_test(stringstore)
  add_spacy_test(span)
  add_spacy_test(token)

endif()
