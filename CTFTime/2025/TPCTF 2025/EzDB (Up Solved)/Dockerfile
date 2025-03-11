FROM ubuntu:22.04

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    socat \
    libc-bin \
    && rm -rf /var/lib/apt/lists/*

# Set up working directory
WORKDIR /app

# Copy the provided libc and dynamic linker
COPY libc.so.6 /lib/x86_64-linux-gnu/libc.so.6
COPY ld-2.35.so /lib64/ld-linux-x86-64.so.2
COPY db /app/db

# Ensure proper permissions
RUN chmod +x /app/db /lib64/ld-linux-x86-64.so.2

# Expose port 1337
EXPOSE 1337

# Run the service using socat
CMD socat TCP-LISTEN:1337,reuseaddr,fork EXEC:/app/db
