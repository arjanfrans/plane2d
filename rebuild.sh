rm -rf build
mkdir -p build
# cp -r data build/data
cd build
cmake ..
make
./src/brecourt
