#!/bin/bash
g++ -o test test_dequeue.cpp -std=c++17 -Wall
./test.exe
rm ./test.ext -f
read -n1