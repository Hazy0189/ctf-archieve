FROM ubuntu@sha256:1f1a2d56de1d604801a9671f301190704c25d604a416f59e03c04f5c6ffee0d6 
## Ubuntu 16.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update --fix-missing && apt-get -y upgrade
RUN apt-get install -y socat

RUN useradd -m pctf

COPY challenge/chal challenge/flag.txt /pctf/

RUN chown -R pctf:pctf /pctf/

WORKDIR /pctf

USER pctf

EXPOSE 1337
CMD ["socat", "TCP-LISTEN:1337,fork", "EXEC:./chal"]