FROM cybersecnatlab/challenge-jail:ubuntu-focal@sha256:a89dad107b158a13c547deadf8aeed5d6e558e0ce3d261955ffde5be3b3f3c9c

COPY libc.so.6 /home/user/libs/libc.so.6
COPY ld-linux-x86-64.so.2 /home/user/libs/ld-linux-x86-64.so.2

COPY chall /home/user/chall

ENV SET_INTERPRETER=/home/user/libs/ld-linux-x86-64.so.2
ENV SET_RPATH=/home/user/libs

ENV FLAG=corn{test}
