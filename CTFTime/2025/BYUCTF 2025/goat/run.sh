#!/bin/sh

docker build -t goat .
docker run  --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 5000:5000 -it goat
