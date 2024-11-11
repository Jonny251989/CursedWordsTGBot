#!/bin/bash -e

script_directory=$(dirname "$(readlink -f "$0")")
full_path=$(readlink -f "$script_directory/build")

mkdir $full_path
cd $full_path
cmake ..
make -j$(nproc)

path_from_bot=$(readlink -f "$full_path/CursedWordsTGBot/CursedWordsTGBot*")
path_to_bot=$(readlink -f "$script_directory/bins/CursedWordsTGBot/")

path_from_unit_tests=$(readlink -f "$full_path/Tests/UnitTests")

path_from_queue_tests=$(readlink -f "$path_from_unit_tests/Queue_Tests/queue_tests*")
path_to_queue_tests=$(readlink -f "$script_directory/bins/Tests/Queue_Tests/")

path_from_parser_tests=$(readlink -f "$path_from_unit_tests/Parser_Tests/parser_tests*")
path_to_parser_tests=$(readlink -f "$script_directory/bins/Tests/Parser_Tests/")

cp $path_from_bot $path_to_bot
echo "script_directory: $script_directory"
echo "path_from_bot: $path_from_bot"
echo "path_to_bot: $path_to_bot"

cp $path_from_queue_tests $path_to_queue_tests
echo "path_from_queue_test: $path_from_queue_test"
echo "path_to_queue_tests: $path_to_queue_tests"

cp $path_from_parser_tests $path_to_parser_tests
echo "path_from_parser_test: $path_from_parser_tests"
echo "path_to_parser_test: $path_to_parser_tests"