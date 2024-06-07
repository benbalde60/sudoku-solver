# Only if you are using visual studio code (if you are using CLion don't worry about this file)
# You might need to change line 11 or 13 based on the location of the SudokuProject executable
[[ -d ./cmake-build-debug ]] && rm -rf ./cmake-build-debug
mkdir -p ./cmake-build-debug
cmake -B ./cmake-build-debug
cmake --build ./cmake-build-debug
echo "----------------------------------------"
echo "------------COMPILATION DONE------------"
echo "----------------------------------------"
# Use following for Windows, delete #
# ./cmake-build-debug/Debug/SudokuProject.exe
# Use following for Mac or Linux, delete #
#./cmake-build-debug/SudokuProject