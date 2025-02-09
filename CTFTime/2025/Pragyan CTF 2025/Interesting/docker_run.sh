#!/bin/sh
docker build --tag=interesting .
docker run -it -p 9001:1337 --rm --name=interesting --user root --entrypoint /bin/bash interesting
