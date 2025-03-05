#!/bin/sh

docker build -t einstein .
docker run  --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 5000:5000 -it einstein
