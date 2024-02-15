cd Google_tests/lib || return
git clone https://github.com/google/googletest .
cd ../../
bash ./build-cmake.bash
cd cmake-build/Google_tests || exit
./Google_Tests_run
