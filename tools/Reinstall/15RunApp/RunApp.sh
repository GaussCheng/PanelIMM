#! /bin/sh

export set QWS_KEYBOARD="linuxinput:/dev/input/event1:repeat-rate=200:repeat-delay=500:keymap=/home/root/IMMTOUCH.qmap"
export set QWS_DISPLAY="Transformed:Rot270:LinuxFB:mmWidth=304:mmHeight=228:0"
export set QWS_SIZE="1024x768"

cd /opt/Qt/apps
./PanelIMM -qws
