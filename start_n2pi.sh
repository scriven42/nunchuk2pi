#!/bin/bash
WIIDRIVER='/home/pi/bin/n2pi'
if pgrep -f "$WIIDRIVER" >/dev/null 2>&1 ; then
    echo "n2pi already running!"
else
    echo "starting n2pi driver!"
    sudo $WIIDRIVER &
fi
