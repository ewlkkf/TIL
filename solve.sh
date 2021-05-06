#!/bin/bash

if [ -z "$1" ]; then
    echo "solve number required."
    exit 0
fi

if [ -d "$1" ]; then
    cd $1 && vim $1.cpp && echo "compiling..." && g++ -c $1.cpp && g++ -o $1 $1.o && echo "compile complete. executing..." && ./$1
else
    mkdir $1 && cp original.cpp ./$1/$1.cpp && cd $1 && vim $1.cpp && echo "compiling..." && g++ -c $1.cpp && g++ -o $1 $1.o && echo "compile complete. executing..." && ./$1
fi
