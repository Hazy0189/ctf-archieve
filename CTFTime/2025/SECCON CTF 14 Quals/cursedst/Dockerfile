FROM ubuntu:24.04@sha256:985be7c735afdf6f18aaa122c23f87d989c30bba4e9aa24c8278912aac339a8d AS base
WORKDIR /app
COPY --chmod=555 st run
RUN echo "FLAG{dummy}" > flag.txt
RUN mv flag.txt flag-$(md5sum flag.txt | awk '{print $1}').txt

FROM pwn.red/jail
COPY --from=base / /srv
ENV JAIL_TIME=300 JAIL_CPU=100 JAIL_MEM=10M
