#!/bin/sh

docker build -t takenote .
docker run  --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 1337:1337 -it takenote
