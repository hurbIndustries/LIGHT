#!/usr/bin/env bash

##   LIGHT
##   install.sh
##   Copyright 2024 - hurbIndustries
##   Originally written by JPD
##   <3 

### NOTE:
### This is a modified copy of the `./install.sh` script used on my personal project `Captainjamason/booruDownloader`.
### FreeBSD declarations were removed as it was not necessary for any libraries used by this. 

if [[ $1 == "--clean-build" ]]; then
        echo "Cleaning build directory..."
        rm -rf ./build/
        echo "Done! Proceeding to build..."
fi
if [[ $1 == "--clean" ]]; then
        echo "Cleaning build directory..."
        rm -rf ./build/
        echo "Done!"
        exit
fi

if ! [ -d ./build/ ]; then
        echo "Build directory not found, Setting up now..."
        meson setup build && cd ./build
else
        echo "Build directory found, Starting compilation..."
        cd ./build
fi

meson compile

if [[  $1 == "--only-build" ]];  then
        echo "All done."
else
        echo "Installing, Requiring elevation to install to /usr/local/bin/ and /etc/."
        sudo cp ./src/light /usr/local/bin/light
        if ! [[ -d /etc/light ]]; then
                sudo mkdir /etc/light
        fi
        sudo cp ./config/conf.json /etc/light/conf.json
fi
