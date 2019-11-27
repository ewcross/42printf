#!/bin/bash

gcc moo.c
./a.out > real
gcc my_moo.c libftprintf.a
./a.out > mine
diff real mine > o
rm real mine
