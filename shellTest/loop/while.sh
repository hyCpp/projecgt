printf "enter username:"
read user
while true
do
    if who | grep "$user" > user.txt
    then
        break
    fi
    sleep 3
done
