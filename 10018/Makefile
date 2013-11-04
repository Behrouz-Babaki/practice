.PHONEY : all
#CPPFLAGS = --coverage
#CPPFLAGS+=-std=c++0x
all : 10018

10018 : 10018.o
	g++ $(CPPFLAGS) -g  $< -o $@

%.o : %.cpp
	g++ $(CPPFLAGS)  -g -c  $< -o $@ 