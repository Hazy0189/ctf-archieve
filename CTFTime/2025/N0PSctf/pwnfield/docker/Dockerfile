FROM ubuntu:22.04

WORKDIR /app

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install socat -y
RUN apt-get install strace -y
RUN useradd -m pwn

COPY ./src/pwnfield ./pwnfield
COPY ./flag.txt ./flag.txt
RUN ln -s /bin/bash /app/sh


RUN chown -R root:root /app
RUN chmod -R 555 /app
RUN chmod 644 /app/flag.txt

CMD socat TCP-LISTEN:1235,reuseaddr,fork EXEC:"./pwnfield",pty,rawer,echo=0