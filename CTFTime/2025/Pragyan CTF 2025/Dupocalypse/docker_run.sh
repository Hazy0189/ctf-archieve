#!/bin/sh
docker build --tag=dupocalypse .
docker run -it -p 9004:1337 --rm --name=dupocalypse --entrypoint /bin/bash --user root dupocalypse
