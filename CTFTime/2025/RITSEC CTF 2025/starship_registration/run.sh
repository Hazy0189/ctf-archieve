#!/bin/sh

docker build -t registration .
docker run  --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 1574:1574 -it registration
