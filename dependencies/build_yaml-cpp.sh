sudo apt-get install libboost-all-dev
cd yaml-cpp
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
