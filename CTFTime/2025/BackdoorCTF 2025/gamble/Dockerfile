FROM ubuntu@sha256:4fdf0125919d24aec972544669dcd7d6a26a8ad7e6561c73d5549bd6db258ac2

RUN apt-get update -y && apt-get install -y socat && rm -rf /var/lib/apt/lists/*

COPY ./chal /pwn/chal
COPY ./flag.txt /pwn/flag.txt
COPY ./start.sh /start.sh
RUN chmod +x /start.sh /pwn/chal

CMD ["/start.sh"]

EXPOSE 8004
