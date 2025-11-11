#!/bin/sh

docker run --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 1024:1024 -it $(docker build -q -t notes .)
