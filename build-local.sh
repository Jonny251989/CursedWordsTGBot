#!/bin/bash -e

project_directory=$(dirname "$(readlink -f "$0")")

cd $project_directory

mkdir -p build
cd build
: ${TGBOT_CPP_INSTALL_PFEFIX:=""}

cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./build -DTGBOT_CPP_INSTALL_PFEFIX=$TGBOT_CPP_INSTALL_PFEFIX
make -j$(nproc)

mkdir -p ../bins/CursedWordsTGBot
mkdir -p ../bins/Tests/Queue_Tests
mkdir -p ../bins/Tests/Parser_Tests
mkdir -p ../bins/Tests/SignalHandler_Tests

cp ./CursedWordsTGBot/CursedWordsTGBot* ../bins/CursedWordsTGBot/
cp ./Tests/UnitTests/Queue_Tests/queue_tests* ../bins/Tests/Queue_Tests/
cp ./Tests/UnitTests/Parser_Tests/parser_tests* ../bins/Tests/Parser_Tests/
cp ./Tests/UnitTests/SignalHandler_Tests/signalhandler_tests* ../bins/Tests/SignalHandler_Tests/