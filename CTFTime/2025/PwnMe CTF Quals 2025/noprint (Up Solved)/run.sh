#!/bin/sh

docker build -t noprint .
docker run --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined \
    --rm -p 1337:1337 -it noprint
