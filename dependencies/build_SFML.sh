#!/bin/sh

sudo apt-get install libx11-dev libxcb1-dev libx11-xcb-dev libxcb-randr0-dev libxcb-image0-dev libgl1-mesa-dev libudev-dev libfreetype6-dev libjpeg-dev libopenal-dev libflac-dev libvorbis-dev -y

cd SFML
mkdir -p build
cd build
cmake ..
sudo make install
rm -rf build
