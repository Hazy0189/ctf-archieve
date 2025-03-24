FROM debian:stable-slim

RUN apt-get update && \
    apt-get install -y socat && \
    rm -rf /var/lib/apt/lists/*

RUN useradd -m ctf

WORKDIR /home/ctf

COPY registration .
COPY flag.txt .

RUN chown root:ctf registration flag.txt && \
    chmod 550 registration && \
    chmod 440 flag.txt

USER ctf

EXPOSE 1574

CMD ["socat", "TCP-LISTEN:1574,fork,reuseaddr", "EXEC:/home/ctf/registration,pty,rawer"]
