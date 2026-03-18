#!/bin/bash
# macOS host script for MLX + Docker
# Start XQuartz if not running
if ! pgrep -x "XQuartz" > /dev/null; then
    echo "Starting XQuartz..."
    open -a XQuartz
    sleep 2  # wait for XQuartz to initialize
fi

# Allow Docker container to connect to X server
echo "Setting X server authorization..."
xhost + 127.0.0.1 >/dev/null 2>&1
