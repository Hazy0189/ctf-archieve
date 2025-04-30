#!/bin/sh

docker build -t onewrite .
docker run  --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 1447:1447 -it onewrite
