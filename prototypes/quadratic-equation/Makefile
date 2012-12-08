all: quadratic-equation

quadratic-equation: source.o
	gcc -ggdb  -o quadratic-equation source.o -ltio -lm
source.o: source.c
	gcc -ggdb -c source.c -o source.o
