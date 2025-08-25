FROM ubuntu@sha256:a08e551cb33850e4740772b38217fc1796a66da2506d312abe51acda354ff061

WORKDIR /app

RUN apt-get update && apt-get install socat -y

COPY flag.txt .
RUN chmod 444 flag.txt

COPY recipe_storage .
RUN chmod 555 recipe_storage

RUN useradd -ms /bin/bash ctf
USER ctf

EXPOSE 1337
CMD socat tcp-l:1337,reuseaddr,fork exec:/app/recipe_storage,pty,echo=0,raw,iexten=0
