#!/bin/bash -e

project_directory=$(dirname "$(readlink -f "$0")")

cd $project_directory

mkdir -p build
cd build
# cmake ..
: ${BASE_PATH:=""}

# Запуск cmake с использованием переменной BASE_PATH
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./build -DBASE_PATH=$BASE_PATH
make -j$(nproc)

mkdir -p ../bins/CursedWordsTGBot
mkdir -p ../bins/Tests/UnitTests/Queue_Tests
mkdir -p ../bins/Tests/UnitTests/Parser_Tests
mkdir -p ../bins/Tests/UnitTests/SignalHandler_Tests
mkdir -p ../bins/Tests/FunctionalTests/Reactor_Tests

cp ./CursedWordsTGBot/CursedWordsTGBot* ../bins/CursedWordsTGBot/
cp ./Tests/UnitTests/Queue_Tests/queue_tests* ../bins/Tests/UnitTests/Queue_Tests/
cp ./Tests/UnitTests/Parser_Tests/parser_tests* ../bins/Tests/UnitTests/Parser_Tests/
cp ./Tests/UnitTests/SignalHandler_Tests/signalhandler_tests* ../bins/Tests/UnitTests/SignalHandler_Tests/
cp ./Tests/FunctionalTests/Reactor_Tests/reactor_tests* ../bins/Tests/FunctionalTests/Reactor_Tests/