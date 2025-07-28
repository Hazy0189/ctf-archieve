FROM ubuntu:24.04@sha256:c920ba4cfca05503764b785c16b76d43c83a6df8d1ab107e7e6610000d94315c

RUN apt-get update && apt-get install -y socat adduser qemu-user-static

RUN adduser arm

WORKDIR /home/arm

COPY ./flag ./flag
COPY ./deploy/chal ./chal
COPY ./deploy/run.sh ./run.sh

RUN chmod 644 ./flag 
RUN chmod 755 ./chal
RUN chmod 755 ./run.sh

USER arm

EXPOSE 1337
CMD socat TCP-LISTEN:1337,reuseaddr,fork EXEC:./run.sh,stderr

