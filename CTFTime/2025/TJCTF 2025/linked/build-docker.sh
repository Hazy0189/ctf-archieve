#!/bin/bash

docker build --tag=linked .
docker run --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -it -p 5000:5000 --rm --name=linked linked