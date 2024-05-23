#!/bin/bash

g++ -o InputGenerator.exe src.cc
rm out.txt
rm correct.txt
while true; do
    ./InputGenerator.exe > gen_test.inp
    ./program.exe < gen_test.inp > out.txt
    ./correct.exe < gen_test.inp > correct.txt
    if !(cmp -s out.txt correct.txt); then
        break
    fi
    echo "Successful run"
done
kompare out.txt correct.txt