#!/bin/sh

DOCKER_BUILDKIT=0 docker build --network=host -t notes .
docker run --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 1337:1337 -it notes
