FROM ubuntu:22.04

RUN apt-get update
RUN apt-get -y install xinetd

RUN useradd -m chal
USER chal
WORKDIR /home/chal

CMD ["/usr/sbin/xinetd", "-dontfork"]
