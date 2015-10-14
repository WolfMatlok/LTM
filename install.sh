#!/bin/bash
echo "rolling out bins"
sudo cp GUI_HTML/index.html /var/www/
sudo cp dist/Debug/GNU-Linux-x86/ltm /usr/lib/cgi-bin/ltm.cgi
echo "finished"