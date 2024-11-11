#!/bin/bash -e

project_directory=$(dirname "$(readlink -f "$0")")

cd $project_directory

mkdir -p build
cd build
cmake ..
make -j$(nproc)

cp -p ./CursedWordsTGBot/CursedWordsTGBot* ../bins/CursedWordsTGBot/
cp -p ./Tests/UnitTests/Queue_Tests/queue_tests* ../bins/Tests/Queue_Tests/
cp -p ./Tests/UnitTests/Parser_Tests/parser_tests* ../bins/Tests/Parser_Tests/