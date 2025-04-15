#!/bin/bash

# Удаление Webhook у Telegram-бота, чтобы избежать конфликта с getUpdates
echo "Deleting Telegram webhook to avoid getUpdates conflict..."
echo "TELEGRAM_BOT_TOKEN starts with: ${TELEGRAM_BOT_TOKEN:0:5}..."

curl -s -X POST "https://api.telegram.org/bot${TELEGRAM_BOT_TOKEN}/deleteWebhook"

# Запуск тестов в контейнере test_runner
docker-compose run --rm test_runner
