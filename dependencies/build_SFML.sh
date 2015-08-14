#!/bin/sh

sudo apt-get install -y libx11-dev libxcb1-dev libx11-xcb-dev libxcb-randr0-dev libxcb-image0-dev libgl1-mesa-dev libudev-dev libfreetype6-dev libjpeg-dev libopenal-dev libflac-dev libvorbis-dev -y
sudo apt-get install -y libboost-filesystem-dev libboost-system-dev

cd SFML
mkdir -p build
cd build
cmake DCMAKE_BUILD_TYPE=Release ..
sudo make install
rm -rf build
