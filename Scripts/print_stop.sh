#!/bin/sh
systemctl stop org.cups.cupsd.service
systemctl disable org.cups.cupsd.service
systemctl stop cups-browsed.service
systemctl disable cups-browsed.service
systemctl stop avahi-daemon.service
systemctl disable avahi-daemon.service
systemctl status | grep cup
systemctl status | grep avahi

