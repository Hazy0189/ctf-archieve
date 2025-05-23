#!/bin/bash
docker build --tag=picture-magic .
docker run -p 1337:1337 --rm --name=picture-magic picture-magic