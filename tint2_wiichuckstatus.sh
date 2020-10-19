#!/bin/bash
# https://www.flaticon.com/free-icon/wii-controller_668538
# Icon made by https://www.flaticon.com/authors/smashicons/Smashicons from www.flaticon.com
# And the no-nunchuck.png was created using https://www.online-image-editor.com/
# by Adam Scriven 20201018
WIIDRIVER='/home/pi/bin/n2pi'
if pgrep -f "$WIIDRIVER" >/dev/null 2>&1 ; then
    echo /home/pi/bin/wii-controller.png
else
    echo /home/pi/bin/no-nunchuck.png
fi
