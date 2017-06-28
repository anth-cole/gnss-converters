#!/bin/bash

# Run Travis setup

set -x
set -o errexit
set -o pipefail

function build_haskell () {
    cd haskell
    stack build --test
    cd ../
}

function build_c() {
    cd c
    mkdir build
    cd build
    cmake ../
    make -j4
    cd ../
    cd ../
}

build_c
build_haskell
