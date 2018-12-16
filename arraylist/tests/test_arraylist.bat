@echo off
g++ -o test test_arraylist.cpp -std=c++17 -Wall
./test.exe
del /f /s /q ./test.exe
pause