.PHONEY : all
#CPPFLAGS = --coverage
#CPPFLAGS+=-std=c++0x
all : 10190

10190 : 10190.o
	g++ $(CPPFLAGS) -g  $< -o $@

%.o : %.cpp
	g++ $(CPPFLAGS)  -g -c  $< -o $@ 