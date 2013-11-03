.PHONEY : all
#CPPFLAGS = --coverage
#CPPFLAGS+=-std=c++0x
all : 713

713 : 713.o
	g++ $(CPPFLAGS) -g  $< -o $@

%.o : %.cpp
	g++ $(CPPFLAGS)  -g -c  $< -o $@ 