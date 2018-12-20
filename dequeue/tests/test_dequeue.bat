@echo off
g++ -o test test_dequeue.cpp -std=c++17 -Wall
./test.exe
del /f /s /q ./test.exe
pause