@echo off
g++ -o test test_stack.cpp -std=c++17 -Wall
test.exe
timeout /t 1
del /f /q test.exe
pause