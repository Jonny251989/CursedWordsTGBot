#!/bin/bash -e
source ./set_versions.sh

docker build -t "tgbot_base:${BASE_IMAGE_VERSION}" -f common_images/Dockerfile.base .