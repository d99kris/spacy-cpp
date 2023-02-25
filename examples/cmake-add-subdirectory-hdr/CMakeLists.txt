cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(cmake-addsubdirectory)
set(CMAKE_CXX_STANDARD 11)

set(Python3_FIND_FRAMEWORK "LAST")
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

add_subdirectory(spacy-cpp)

add_executable(exprog1 src/exprog1.cpp)
target_link_libraries(exprog1 PUBLIC spacy-hdr ${Python3_LIBRARIES})
