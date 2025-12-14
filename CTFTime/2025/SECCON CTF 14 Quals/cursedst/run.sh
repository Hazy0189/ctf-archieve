#!/bin/sh

docker run --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 5000:5000 -it $(docker build -q -t notes .)
