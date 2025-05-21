#!/bin/bash

docker build --tag=dreamdiary2 .
docker run -it -p 1337:1337 --rm --name=dreamdiary2 dreamdiary2