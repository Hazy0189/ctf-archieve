FROM ubuntu@sha256:965fbcae990b0467ed5657caceaec165018ef44a4d2d46c7cdea80a9dff0d1ea as app
ENV DEBIAN_FRONTEND=noninteractive
RUN apt -y update
RUN apt-get install patchelf -y

COPY ./d8 /app/d8
COPY ./snapshot_blob.bin /app/snapshot_blob.bin
COPY ./flag.txt /app/flag.txt
COPY ./server /app/run

RUN chmod 555 /app/flag.txt
RUN chmod +x /app/d8
RUN chmod +x /app/run

FROM pwn.red/jail
COPY --from=app / /srv
ENV JAIL_MEM=256M
ENV JAIL_PORT=2468
ENV JAIL_TMP_SIZE=1
ENV JAIL_PIDS=40

