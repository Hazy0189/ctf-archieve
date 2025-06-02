#!/bin/bash

docker build --tag=pwnfield .
docker run -it -p 1235:1235 --rm --name=pwnfield pwnfield
