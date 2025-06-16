#!/bin/bash

docker build --tag=debugable3 .
docker run -it --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 5000:5000 --rm --name=debugable3 debugable3