#!/bin/bash

for i in $(seq 0 20)
do
    NUM="${i}"
    ((i < 10)) && NUM="0${NUM}"

    ./solution.out < input${NUM}.txt > output${NUM}.txt
    

done
