# use the jail base image
FROM pwn.red/jail
# copy the root files from any Docker image
COPY --from=ubuntu / /srv
# setup the binary to run
RUN mkdir /srv/app
COPY chall /srv/app/run
COPY flag.txt /srv/app