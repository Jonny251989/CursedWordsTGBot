#!/bin/bash

# Поднятие контейнеров
docker-compose -f docker-compose.ci.yml up -d grpc_server test_runner
