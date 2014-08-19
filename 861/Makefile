.PHONY : all doc clean

MAINNAME = 861
CXX = g++
CC = gcc
CFLAGS = -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE

all : $(MAINNAME)

$(MAINNAME) : $(MAINNAME).o
	$(CC) $(CFLAGS)  $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c  $< -o $@ 

clean:
	@ rm -f *.o *~ core $(MAINNAME)

INPUT = input
test:	$(MAINNAME)
	@ echo "input:"
	@ cat $(INPUT)
	@ echo "output:"
	@ cat $(INPUT) | ./$(MAINNAME)