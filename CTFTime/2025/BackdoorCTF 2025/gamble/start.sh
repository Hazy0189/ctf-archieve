#!/bin/sh
cd /pwn
socat TCP-LISTEN:8004,reuseaddr,fork EXEC:./chal