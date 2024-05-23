#!/bin/bash

g++ -o samples/inputs samples/inputs.cc
rm out.txt
rm correct.txt
while true; do
    samples/inputs > samples/testinp.inp
    ./program.exe < samples/testinp.inp > out.txt
    ./correct.exe < samples/testinp.inp > correct.txt
    if !(cmp -s out.txt correct.txt); then
        break
    fi
    echo "Successful run"
done
kompare out.txt correct.txt