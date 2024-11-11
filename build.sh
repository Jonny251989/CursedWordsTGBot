#!/bin/bash -e

mkdir build
cd build
cmake ..
make -j$(nproc)
cp -r ./CursedWordsTGBot* ../bins/CursedWordsTGBot/
cp ./Tests/UnitTests/Queue_Tests/queue_test* ../bins/Tests/Queue_test/
cp ./Tests/UnitTests/Parser_Tests/parser_tests* ../bins/Tests/Parser_tests/


#cp ./CursedWordsTGBot/CursedWordsTGBot* /home/ivan/git_projects/CursedWordsTGBot/bins/CursedWordsTGBot/
#cp ./Tests/UnitTests/Queue_Tests/queue_test* /home/ivan/git_projects/CursedWordsTGBot/bins/Tests/Queue_test/
#cp ./Tests/UnitTests/Parser_Tests/parser_tests* /home/ivan/git_projects/CursedWordsTGBot/bins/Tests/Parser_tests/