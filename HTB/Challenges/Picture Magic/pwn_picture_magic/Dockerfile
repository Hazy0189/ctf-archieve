FROM ubuntu:22.04

# Update all
RUN apt update --fix-missing && \
 apt install -y socat && \
 rm -rf /var/lib/apt/lists/*

# Create ctf-user
RUN groupadd -r ctf && useradd -r -g ctf ctf

# Copy directory
ADD challenge/ /home/ctf/

# Set permissions
RUN chown -R root:ctf /home/ctf
RUN chmod 440 /home/ctf/flag.txt
RUN chmod 750 /home/ctf/picture_magic
RUN chmod 750 /home/ctf/libc.so.6
RUN chmod 750 /home/ctf/ld-2.36.so

# Switch user
USER ctf
WORKDIR /home/ctf

# Run program
EXPOSE 1337
ENTRYPOINT ["socat", "tcp-l:1337,reuseaddr,fork", "EXEC:./picture_magic"]
