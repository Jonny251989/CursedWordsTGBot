#!/bin/bash

# Ждём готовности grpc_server (максимум 5 минут)
docker compose wait --timeout 300 --condition=healthy grpc_server

# Запускаем тесты
docker compose run --rm test_runner