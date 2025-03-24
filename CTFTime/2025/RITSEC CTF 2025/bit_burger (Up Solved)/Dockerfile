
FROM pwn.red/jail
COPY --from=ubuntu:22.04 / /srv

COPY bit_burger.bin /srv/app/run
COPY flag.txt /srv/app/flag.txt