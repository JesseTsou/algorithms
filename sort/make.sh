#!/bin/sh

if [ $# -eq 0 ];then
	rm -rf a.out *.gch
	gcc -g -std=c99 main.c generate.* sort.* print.*
else
	rm -rf a.out *.gch
fi

