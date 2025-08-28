# Dockerfile (no nsjail)
FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

# Install only what we need at runtime
RUN apt-get update && apt-get install -y --no-install-recommends \
    socat \
    python3 \
    ca-certificates \
 && rm -rf /var/lib/apt/lists/*

# Create unprivileged user
RUN useradd -m -u 1000 ctf
WORKDIR /home/ctf

# Bring in your files
COPY main /home/ctf/main
COPY flag.txt /home/ctf/flag.txt
COPY run.sh /home/ctf/run.sh

# Permissions (read/execute only), and hand ownership to the non-root user
RUN chmod 0555 /home/ctf/main /home/ctf/run.sh \
 && chmod 0444 /home/ctf/flag.txt \
 && chown -R ctf:ctf /home/ctf

USER ctf
EXPOSE 5000

# If run.sh expects stdin/stdout (like under nsjail -Mo), use socat to spawn one
# instance per connection and wire it to the network socket.
#
# Tip: if your run.sh already binds to a port itself, replace this CMD with:
#   CMD ["/home/ctf/run.sh"]
CMD ["socat", "-dd", "TCP-LISTEN:5000,reuseaddr,fork,nodelay", "EXEC:/home/ctf/run.sh,pty,stderr,setsid,sigint,ctty"]
