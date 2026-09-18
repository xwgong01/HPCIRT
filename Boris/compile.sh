#!/usr/bin/env bash

set -euo pipefail

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
build_dir="$script_dir/build"

mkdir -p "$build_dir"

"${CXX:-g++}" -std=c++17 -Wall -Wextra -Wpedantic \
    "$script_dir/Simulation.cpp" \
    -o "$build_dir/simulation"
