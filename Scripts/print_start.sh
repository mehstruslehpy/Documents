#!/bin/sh
systemctl start org.cups.cupsd.service
systemctl enable org.cups.cupsd.service
systemctl start cups-browsed.service
systemctl enable cups-browsed.service
systemctl start avahi-daemon.service 
systemctl enable avahi-daemon.service
systemctl status | grep cup
systemctl status | grep avahi

