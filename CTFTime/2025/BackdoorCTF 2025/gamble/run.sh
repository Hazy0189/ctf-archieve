#!/bin/sh

docker run --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 8004:8004 -it $(docker build -q -t notes .)
