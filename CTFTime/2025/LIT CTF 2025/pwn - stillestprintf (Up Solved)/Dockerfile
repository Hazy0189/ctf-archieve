# Pin a base (any recent Ubuntu works since we ship our own glibc 2.24)
FROM ubuntu:22.04

ARG DEBIAN_FRONTEND=noninteractive

# Tools you already used + socat for TCP listener
RUN apt-get -y update && apt-get install -y \
    autoconf \
    bison \
    flex \
    gcc \
    g++ \
    git \
    libprotobuf-dev \
    libnl-route-3-dev \
    libseccomp-dev \
    libtool \
    make \
    pkg-config \
    protobuf-compiler \
    curl \
    build-essential \
    ca-certificates \
    python3 \
    python3-dev \
    python3-pip \
    python3-venv \
    binutils-gold \
    socat \
 && rm -rf /var/lib/apt/lists/*

# Non-root user (similar to nsjail's 99999 uid)
RUN useradd -m -u 99999 -s /bin/bash ctf

# Python venv
RUN python3 -m venv /home/ctf/venv
ENV PATH=/home/ctf/venv/bin:$PATH

# App files
WORKDIR /app
COPY main_patched ./main
COPY libc.so.6 ./libc-2.24.so
COPY ld-2.24.so ./ld-2.24.so
COPY flag.txt ./flag.txt

# Your run script (we’ll replace below); make sure it’s executable
COPY run.sh ./run.sh
RUN chmod +x /app/run.sh

# Helpful symlink (not strictly required because we’ll call loader explicitly)
RUN ln -sf /app/libc-2.24.so /app/libc.so.6

# Lock down ownership/permissions a bit
RUN chown -R ctf:ctf /app && chmod 444 /app/flag.txt && chmod 555 /app/main

# Drop privileges
USER ctf

# Expose service port
EXPOSE 5000

# Start a listener that forks per-connection and runs your run.sh
# -T 120: idle timeout; adjust as needed
# pty,raw,echo=0: classic pwn-friendly TTY behavior
CMD socat -T 120 TCP-LISTEN:5000,reuseaddr,fork \
     EXEC:'/app/run.sh',pty,setsid,ctty,raw,echo=0
