#!/bin/bash

#Update
sudo apt update

#Install programs from repo
sudo apt install git gcc cmake g++ gcc-multilib build-essential emacs fonts-indic fonts-powerline wget tmux curl  -y

#Install GIT dependencies
sudo apt install libz-dev libssl-dev libcurl4-gnutls-dev libexpat1-dev gettext -y

#Downgrade Python3 to Python2
sudo apt install python-is-python2 -y

#Download Debian Packages
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb


#Install Debian Packages
sudo dpkg -i *.deb
sudo apt install -f -y

#Clean up Debian Packages


#Powerline Setup
# refer to this link for install..
# https://ubunlog.com/en/powerline-personaliza-linea-comandos/
wget https://github.com/powerline/powerline/raw/develop/font/PowerlineSymbols.otf
wget https://github.com/powerline/powerline/raw/develop/font/10-powerline-symbols.conf

install -d -o sgc -g sgc /home/sgc/.local/share/fonts
chown sgc:sgc /home/sgc/.local/share/fonts -R

install -d -o sgc -g sgc /home/sgc/.config/fontconfig/conf.d
chown sgc:sgc /home/sgc/.config/fontconfig -R

mv PowerlineSymbols.otf /home/sgc/.local/share/fonts/
fc-cache -vf /home/sgc/.local/share/fonts/
mv 10-powerline-symbols.conf /home/sgc/.config/fontconfig/conf.d/

#NOTE, must manually modify .bashrc, see link above

#Spacemacs Setup
git clone https://github.com/syl20bnr/spacemacs $HOME/.emacs.d

#NOTE: run source ~/.bashrc after powerline install to refresh changes.

