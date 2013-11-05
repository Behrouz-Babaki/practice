.PHONEY : all
#CPPFLAGS = --coverage
#CPPFLAGS+=-std=c++0x
all : test test2 test3

test2: test2.o
	g++ $(CPPFLAGS) -g  $< -o $@

test3: test3.o
	g++ $(CPPFLAGS) -g  $< -o $@

test : test.o
	g++ $(CPPFLAGS) -g  $< -o $@

%.o : %.cpp
	g++ $(CPPFLAGS)  -g -c  $< -o $@ 