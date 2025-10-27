FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN /usr/sbin/userdel -r ubuntu 
RUN /usr/sbin/useradd --no-create-home -u 1000 user

RUN apt-get -y update && apt-get -y install socat

COPY ctf /home/user/
COPY flag /

WORKDIR /

CMD ["/usr/bin/socat", "TCP-LISTEN:4443,reuseaddr,fork", "EXEC:/home/user/ctf"]

