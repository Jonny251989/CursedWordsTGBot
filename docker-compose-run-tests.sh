#!/bin/bash

# Запускаем тесты
docker compose run --rm running_bot
docker compose run --rm generator
docker compose run --rm checker