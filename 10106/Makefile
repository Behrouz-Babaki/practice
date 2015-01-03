.PHONEY : all
#CPPFLAGS = --coverage
#CPPFLAGS+=-std=c++0x
all : 10106

10106 : 10106.o
	g++ $(CPPFLAGS) -g  $< -o $@

%.o : %.cpp
	g++ $(CPPFLAGS)  -g -c  $< -o $@ 