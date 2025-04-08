#!/bin/bash

# Запуск тестов в контейнере test_runner
docker-compose -f docker-compose.ci.yml run --rm test_runner
