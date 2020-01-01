#!/bin/sh
# Run by: bash run.sh
clear
mv main_mod.txt main_mod.c
gcc *.c
rm gnl/12.txt
./a.out > gnl/12.txt
cd gnl
gcc *.c -D BUFFER_SIZE=10
./a.out
rm a.out
cd ..
mv main_mod.c main_mod.txt