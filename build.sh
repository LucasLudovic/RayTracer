#!/bin/bash
if [ "$1" = "-d" ]; then
    cd .build;
    make clean;
else
    if [ ! -d ".build"]; then
        mkdir .build
    fi
    cmake -B .build
    cd .build
    make
fi
