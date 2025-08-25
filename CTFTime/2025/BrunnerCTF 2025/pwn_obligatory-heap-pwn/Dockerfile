FROM ubuntu@sha256:a08e551cb33850e4740772b38217fc1796a66da2506d312abe51acda354ff061

COPY ./obligatory_heap_pwn .
COPY ./flag.txt .
RUN apt-get update
RUN yes | apt-get install socat

RUN chmod +x obligatory_heap_pwn 

CMD ["socat", "tcp-l:1337,reuseaddr,fork", "EXEC:'./obligatory_heap_pwn'"]
