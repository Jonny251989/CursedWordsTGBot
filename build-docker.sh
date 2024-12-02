#!/bin/bash -e

docker build -t "tgbot_base:1.0" -f common_images/Dockerfile.base .

docker build -t "tgbot:1.0" --build-arg BASE_IMAGE_VERSION=1.0 -f target_images/Dockerfile.CursedWordsTgBot .

docker run -it -e command_line_arguments="-token XXXXX" tgbot:1.0 