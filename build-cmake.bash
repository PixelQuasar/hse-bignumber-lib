cd Google_tests/lib || return
git clone https://github.com/google/googletest .
cd ../../

mkdir cmake-build
cd cmake-build || exit
cmake ..
cd ../
cmake --build ./cmake-build

cd Bignumber_lib || exit
mkdir cmake-build
cd cmake-build || exit
cmake ..
cd ../
cmake --build ./cmake-build

cd ../Google_tests || exit
mkdir cmake-build
cd cmake-build || exit
cmake ..
cd ../
cmake --build ./cmake-build


