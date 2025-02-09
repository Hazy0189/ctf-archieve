#!/bin/sh
docker build --tag=the_heap_of_the_brave .
docker run -it -p 9002:1337 --rm --name=the_heap_of_the_brave the_heap_of_the_brave