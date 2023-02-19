cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(cmake-addsubdirectory)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(spacy-cpp)

add_executable(exprog2 src/exprog2.cpp)
target_link_libraries(exprog2 PUBLIC spacy)
