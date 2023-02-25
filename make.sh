#!/usr/bin/env bash

# make.sh
#
# Copyright (C) 2020-2023 Kristofer Berggren
# All rights reserved.
#
# See LICENSE for redistribution information.

# exiterr
exiterr()
{
  >&2 echo "${1}"
  exit 1
}

# process arguments
DEPS="0"
BUILD="0"
TESTS="0"
DOC="0"
INSTALL="0"
SRC="0"
EXAMPLES="0"
case "${1%/}" in
  deps)
    DEPS="1"
    ;;

  build)
    BUILD="1"
    ;;

  test*)
    BUILD="1"
    TESTS="1"
    ;;

  doc)
    BUILD="1"
    DOC="1"
    ;;

  install)
    BUILD="1"
    INSTALL="1"
    ;;

  examples)
    EXAMPLES="1"
    ;;

  src)
    SRC="1"
    ;;

  all)
    DEPS="1"
    BUILD="1"
    TESTS="1"
    DOC="1"
    INSTALL="1"
    EXAMPLES="1"
    ;;

  *)
    echo "usage: make.sh <deps|build|tests|doc|install|all>"
    echo "  deps      - install project dependencies"
    echo "  build     - perform build"
    echo "  tests     - perform build and run tests"
    echo "  doc       - perform build and generate documentation"
    echo "  install   - perform build and install"
    echo "  examples  - build and run examples"
    echo "  all       - perform all actions above"
    echo "  src       - perform source code reformatting"
    exit 1
    ;;
esac

# deps
if [[ "${DEPS}" == "1" ]]; then
  OS="$(uname)"
  if [ "${OS}" == "Linux" ]; then
    DISTRO="$(lsb_release -i | awk -F':\t' '{print $2}')"
    if [[ "${DISTRO}" == "Ubuntu" ]]; then
      pip3 install -U spacy && python3 -m spacy download en_core_web_sm || exiterr "deps failed (linux), exiting."
    else
      exiterr "deps failed (unsupported linux distro ${DISTRO}), exiting."
    fi
  elif [ "${OS}" == "Darwin" ]; then
    pip3 install -U spacy && python3 -m spacy download en_core_web_sm || exiterr "deps failed (mac), exiting."
  else
    exiterr "deps failed (unsupported os ${OS}), exiting."
  fi
fi

# src
if [[ "${SRC}" == "1" ]]; then
  uncrustify -c etc/uncrustify.cfg --replace --no-backup src/spacy/*.* tests/*.* || \
    exiterr "unrustify failed, exiting."
fi

# build
if [[ "${BUILD}" == "1" ]]; then
  OS="$(uname)"
  MAKEARGS=""
  if [ "${OS}" == "Linux" ]; then
    MAKEARGS="-j$(nproc)"
  elif [ "${OS}" == "Darwin" ]; then
    MAKEARGS="-j$(sysctl -n hw.ncpu)"
  fi
  mkdir -p build && cd build && cmake -DSPACYCPP_BUILD_TESTS=ON .. && make ${MAKEARGS} && cd .. || exiterr "build failed, exiting."
fi

# tests
if [[ "${TESTS}" == "1" ]]; then
  cd build && ctest --output-on-failure && cd .. || exiterr "tests failed, exiting."
fi

# doc
if [[ "${DOC}" == "1" ]]; then
  true || exiterr "doc failed, exiting."
fi

# install
if [[ "${INSTALL}" == "1" ]]; then
  OS="$(uname)"
  if [ "${OS}" == "Linux" ]; then
    cd build && sudo make install && cd .. || exiterr "install failed (linux), exiting."
  elif [ "${OS}" == "Darwin" ]; then
    cd build && make install && cd .. || exiterr "install failed (mac), exiting."
  else
    exiterr "install failed (unsupported os ${OS}), exiting."
  fi
fi

# examples
if [[ "${EXAMPLES}" == "1" ]]; then
  OS="$(uname)"
  MAKEARGS=""
  if [ "${OS}" == "Linux" ]; then
    MAKEARGS="-j$(nproc)"
  elif [ "${OS}" == "Darwin" ]; then
    MAKEARGS="-j$(sysctl -n hw.ncpu)"
  fi

  BASEDIR="$(pwd)"

  rm -f examples/cmake-add-subdirectory-*/spacy-cpp || exiterr "example pre-cleanup failed, exiting."

  cd examples/cmake-add-subdirectory-hdr && ln -s ../.. spacy-cpp && mkdir -p build && cd build && cmake .. && make ${MAKEARGS} && ./exprog1 > /dev/null && cd ${BASEDIR} || exiterr "example failed, exiting."

  cd examples/cmake-add-subdirectory-lib && ln -s ../.. spacy-cpp && mkdir -p build && cd build && cmake .. && make ${MAKEARGS} && ./exprog2 > /dev/null && cd ${BASEDIR} || exiterr "example failed, exiting."
fi

# exit
exit 0
