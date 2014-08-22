.PHONY : all doc clean test valgrind callgrind

SHELL := /bin/bash
MAINNAME = 193
CXX = g++
CC = gcc
CFLAGS = -g -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE

all : $(MAINNAME)

$(MAINNAME) : $(MAINNAME).o
	$(CC) $(CFLAGS)  $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c  $< -o $@ 

clean:
	@ rm -f *.o *~ core $(MAINNAME) callgrind.out.*

INPUT = input
OUTPUT = output
test:	$(MAINNAME)
	@ echo "input:"
	@ cat $(INPUT)
	@ echo "output:"
	@ cat $(INPUT) | ./$(MAINNAME)
	@ echo 
	@ diff <(cat $(OUTPUT)) <(cat $(INPUT) | ./$(MAINNAME)) || exit 0

callgrind: $(MAINNAME)
	@ valgrind --tool=callgrind --input-fd=3 ./$(MAINNAME) < $(INPUT) 3</dev/tty

valgrind: $(MAINNAME)
	@ valgrind  --input-fd=3 ./$(MAINNAME) < $(INPUT) 3</dev/tty