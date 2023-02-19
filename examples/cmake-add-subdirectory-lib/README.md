CMake Add Subdirectory Example Project Using Linked Library
===========================================================

Usage
-----
Copy the directory `cmake-add-subdirectory-lib` to a new location and then
place a copy of `spacy-cpp` within it. Example:

    cp -a spacy-cpp/examples/cmake-add-subdirectory-lib ~/myproj
    cp -a spacy-cpp ~/myproj/

For testing the example project in-place without copying it to a new
location, one can simulate the above by setting up a symbolic link:

    ln -s ../.. spacy-cpp

Build Steps
-----------
Commands to build the example project:

    mkdir -p build && cd build && cmake .. && make

