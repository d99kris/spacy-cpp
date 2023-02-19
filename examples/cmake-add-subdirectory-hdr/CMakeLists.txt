cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(cmake-addsubdirectory)
set(CMAKE_CXX_STANDARD 11)

find_package(PythonLibs 3 REQUIRED)
find_package(PythonInterp 3 REQUIRED)

add_subdirectory(spacy-cpp)

add_executable(exprog1 src/exprog1.cpp)
target_link_libraries(exprog1 PUBLIC spacy-hdr ${PYTHON_LIBRARIES})
