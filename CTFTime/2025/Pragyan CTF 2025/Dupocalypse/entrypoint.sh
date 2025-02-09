#!/bin/sh

while true; do
        ./chal
        if [ $? -eq 130 ]; then
                echo "Received keyboard interrupt. Exiting..."
                break
        fi
        echo "Restarting..."
done
