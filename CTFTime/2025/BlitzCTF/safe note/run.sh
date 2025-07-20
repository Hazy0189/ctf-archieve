#!/bin/sh
docker build -t safenote .
docker run  --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 9088:9088 -it safenote
