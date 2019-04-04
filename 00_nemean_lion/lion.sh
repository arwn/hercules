#!/usr/bin/env sh
if dpkg -s openssh-server ; then
	echo "sshd installed"
else
	apt -y install openssh-server
fi
mkdir -p /etc/ssh/
echo "Port 6969" >> /etc/ssh/sshd_config
service sshd restart
