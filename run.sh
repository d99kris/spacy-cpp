#!/usr/bin/env bash

# run tests
mkdir -p build && cd build && cmake .. && make && ctest --output-on-failure

exit ${?}
