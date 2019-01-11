#!/bin/bash
g++ -o test test_queue.cpp -std=c++17 -Wall
./test.exe
sleep 1
rm ./test.exe -f
read -n1