cd Google_tests/lib || return
git clone https://github.com/google/googletest .
cd ../../

mkdir cmake-build
cd cmake-build || exit
cmake ..
cd ../
cmake --build ./cmake-build
