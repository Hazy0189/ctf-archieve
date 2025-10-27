#!/bin/sh

docker run --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 4443:4443 -it $(docker build -q -t notes .)
