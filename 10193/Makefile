.PHONEY : all
#CPPFLAGS = --coverage
#CPPFLAGS+=-std=c++0x
all : 10193

10193 : 10193.o
	g++ $(CPPFLAGS) -g  $< -o $@

%.o : %.cpp
	g++ $(CPPFLAGS)  -g -c  $< -o $@ 