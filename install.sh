#!/bin/bash
echo "rolling out bins"
pwd
sudo cp GUI_HTML/index.html /var/www/
sudo cp dist/Debug/GNU-Linux-x86/ltm /usr/lib/cgi-bin/ltm.cgi
sudo chmod 555 /usr/lib/cgi-bin/ltm.cgi
echo "finished"