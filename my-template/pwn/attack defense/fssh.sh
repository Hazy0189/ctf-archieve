#!/bin/bash

ip="$1"
port="${2:-22}"
pass="$3"

opts="-o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null -o GlobalKnownHostsFile=/dev/null -o ConnectTimeout=3"

if [ -n "$pass" ]; then
    sshpass -p "$pass" ssh $opts -p "$port" root@"$ip"
else
    ssh $opts -o BatchMode=yes -i ~/hazy -p "$port" root@"$ip"
fi
