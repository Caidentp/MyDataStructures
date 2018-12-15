#!/bin/bash
g++ -o test test_linkedlist.cpp -std=c++17 -Wall
./test.exe
rm ./test.exe -f
read -n1
