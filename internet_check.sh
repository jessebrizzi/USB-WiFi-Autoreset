#! /bin/bash

while true
do
    wget -q --tries=10 --timeout=20 -O - http://google.com > /dev/null
    if ! [[ $? -eq 0 ]]; then
      kdialog --title "OFFLINE" --passivepopup "This popup will disappear in 5 seconds" 5 &
      sudo /home/jesse/Documents/internet_fix/internet_fix
    fi
    sleep 10
done
