@echo off
g++ -o test test_heap.cpp -std=c++17 -Wall
./test.exe
del ./test.exe /f /q
pause