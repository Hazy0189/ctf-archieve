FROM ubuntu@sha256:8e5c4f0285ecbb4ead070431d29b576a530d3166df73ec44affc1cd27555141b
## Ubuntu 20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update --fix-missing && apt-get -y upgrade

RUN useradd -m pctf

COPY entrypoint.sh /

COPY challenge/chal challenge/flag.txt /pctf/

RUN chown -R pctf:pctf /pctf/

WORKDIR /pctf

USER pctf

ENV PORT=1337

ENTRYPOINT [ "/entrypoint.sh" ]
