FROM ubuntu:24.04

RUN apt-get update && apt-get upgrade -y && \
		apt-get install -y \
			xinetd \
			iproute2

RUN groupadd -r user && useradd -r -g user user

COPY --chown=root:user ./start.sh /home/user/start.sh
COPY --chown=root:root ./ctf.conf /etc/xinetd.d/ctf
COPY --chown=root:user ./tasks /home/user/tasks
COPY --chown=root:user ./flag.txt /home/user/flag.txt

WORKDIR /home/user

RUN chmod 444 ./flag.txt && \
		chmod 555 ./tasks && \
		chmod 555 ./start.sh && \
		chmod 444 /etc/xinetd.d/ctf

USER user

CMD ["xinetd","-dontfork","-f","/etc/xinetd.d/ctf"]