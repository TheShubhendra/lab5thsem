while true; do
    read line < /tmp/pipe
	clear
	cowsay $line | lolcat
done

