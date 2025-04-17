#!/bin/bash

case "$1" in
  up)
    echo "Starting infrastructure..."
    docker compose up -d grpc_server
    docker compose wait --timeout 300 grpc_server
    ;;
  down)
    echo "Stopping infrastructure..."
    docker compose down
    ;;
  *)
    echo "Usage: $0 {up|down}"
    exit 1
    ;;
esac