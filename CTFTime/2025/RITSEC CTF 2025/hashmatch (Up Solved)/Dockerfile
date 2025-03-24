# use the jail base image
FROM pwn.red/jail
# copy the root files from any Docker image
COPY --from=ubuntu / /srv
# setup the binary to run
RUN mkdir /srv/app
copy hashmatch /srv/app/run
copy flag.txt /srv/app/flag.txt
ENV JAIL_TMP_SIZE 255
