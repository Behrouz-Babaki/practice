.PHONY : all doc clean test valgrind callgrind

SHELL := /bin/bash
MAINNAME = 291
CXX = g++
CC = gcc
CCFLAGS = -g -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE
CXXFLAGS = -g -lm -lcrypt -O2 -std=c++0x -pipe -DONLINE_JUDGE

all : $(MAINNAME)

$(MAINNAME) : $(MAINNAME).o
	$(CXX) $(CXXFLAGS)  $< -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c  $< -o $@ 

clean:
	@ rm -f *.o *~ core $(MAINNAME) callgrind.out.*

callgrind: $(MAINNAME)
	@ valgrind --tool=callgrind --input-fd=3 ./$(MAINNAME) < $(INPUT) 3</dev/tty

valgrind: $(MAINNAME)
	@ valgrind  --input-fd=3 ./$(MAINNAME) < $(INPUT) 3</dev/tty