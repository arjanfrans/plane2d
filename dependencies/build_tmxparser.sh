sudo apt-get install -y libtinyxml2-dev zlibc
cd tmxparser 
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
sudo make install
rm -rf build
