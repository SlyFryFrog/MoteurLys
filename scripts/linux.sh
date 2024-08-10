#!/bin/bash

# Check if script is run with sudo
if [ "$EUID" -ne 0 ]; then
    echo "This script requires superuser privileges. Please run with sudo."
    exit 1
fi

apt-get update -y && apt-get upgrade -y
apt-get install -y libgl1-mesa-dev libglew-dev libglfw3-dev \
                   libfreetype6-dev
