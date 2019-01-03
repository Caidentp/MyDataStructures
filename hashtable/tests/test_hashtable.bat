@echo off
g++ -o test test_hashtable.cpp -std=c++17 -Wall
./test.exe
rm /f /q ./test.exe
pause
