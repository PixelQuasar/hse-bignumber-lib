cd Google_tests/lib || exit
git clone https://github.com/google/googletest
cd ../../

#cd Bignumber_lib || exit
#mkdir cmake-build
#cd cmake-build || exit
#cmake ..
#cd ../
#cmake --build ./cmake-build
#
#cd ../Google_tests || exit
#mkdir cmake-build
#cd cmake-build || exit
#cmake ..
#cd ../
#cmake --build ./cmake-build

mkdir cmake-build
cd cmake-build || exit
cmake ..
cd ../
cmake --build ./cmake-build
