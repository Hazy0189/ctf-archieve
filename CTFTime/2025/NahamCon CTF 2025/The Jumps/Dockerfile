FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install -y qemu qemu-system-x86 qemu-utils socat cpio gzip wget 

EXPOSE 1337

RUN useradd -d /home/ctf -m -p ctf -s /bin/bash ctf
RUN echo "ctf:ctf" | chpasswd
RUN ulimit -c 0

WORKDIR /home/ctf
COPY run.sh ./run.sh
COPY bzImage ./bzImage
# COPY exploit ./exploit
COPY fs ./fs
RUN chmod +x *.sh

EXPOSE 1337
USER ctf
CMD socat tcp-l:1337,reuseaddr,fork EXEC:"./run.sh",pty,stderr
