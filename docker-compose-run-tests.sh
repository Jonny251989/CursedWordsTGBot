#!/bin/bash

# Запускаем тесты
docker compose run --rm running_bot
docker compose run --rm generator
#docker-compose wait generator
#send(SIGINT)
#run checker
docker compose run --rm checker