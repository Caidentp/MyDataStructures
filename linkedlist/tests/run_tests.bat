@echo off
g++ -o test test_linkedlist.cpp -std=c++17 -Wall
"%~dp0\test"
del /f /s /q "%~dp0\test.exe"
pause
