FROM debian:stable-slim

EXPOSE 1337

ARG FLAG="flag{thisisadummyflagthisisadummyflag}"

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get -y dist-upgrade
RUN apt-get -y install tini \
        wget \
        ovmf \
        swtpm \
        procps \
        iptables \
        iproute2 \
        apt-utils \
        dnsmasq \
        net-tools \
        qemu-utils \
        ca-certificates \
        netcat-openbsd \
        libguestfs-tools \
        qemu-system

ENV LIBGUESTFS_BACKEND=direct

ADD launch.sh /
ADD firstworldproblem.qcow2 /base.qcow2
RUN chmod +x /launch.sh

RUN printf '%s\n' "$FLAG" > /tmp/flag

RUN qemu-img create -f qcow2 -b /base.qcow2 -F qcow2 /firstworldproblem.qcow2

RUN virt-customize -a /firstworldproblem.qcow2 \
      --copy-in /tmp/flag:/ \
      --run-command 'chmod 400 /flag' \
      --run-command 'passwd -l root' \
      --edit '/etc/ssh/sshd_config:s/^#\?PermitRootLogin.*/PermitRootLogin no/'

ENTRYPOINT ["/usr/bin/tini", "-s", "/launch.sh"]

