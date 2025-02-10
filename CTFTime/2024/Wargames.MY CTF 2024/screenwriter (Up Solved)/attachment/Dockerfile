# sudo docker build .
# sudo docker run -p 13337:13337 <image_id>
FROM ubuntu:22.04@sha256:965fbcae990b0467ed5657caceaec165018ef44a4d2d46c7cdea80a9dff0d1ea

ENV user writer

RUN apt update
RUN apt-get install -y socat

RUN adduser $user
RUN touch /home/$user/script.txt

COPY ./flag /home/$user/flag
COPY ./bee-movie.txt /home/$user/bee-movie.txt
COPY ./chall /home/$user/chall

RUN chown -R root:$user /home/$user
RUN chown root:$user /home/$user/flag
RUN chown root:$user /home/$user/bee-movie.txt
RUN chown root:$user /home/$user/script.txt
RUN chown root:$user /home/$user/chall

RUN chmod 440 /home/$user/flag
RUN chmod 440 /home/$user/bee-movie.txt
RUN chmod 664 /home/$user/script.txt
RUN chmod 755 /home/$user/chall

WORKDIR /home/$user
USER $user
EXPOSE 13337
CMD socat TCP-LISTEN:13337,reuseaddr,fork EXEC:/home/$user/chall

# libc and ld attached is from docker container
# use "patchelf --replace-needed ...", and "patchelf --set-interpreter ..." to set local binary to use same libc and ld as container/remote
