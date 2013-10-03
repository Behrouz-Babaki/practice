.PHONEY : all
#CPPFLAGS = --coverage

all : 151

151 : 151.o
	g++ $(CPPFLAGS) -g  $< -o $@

%.o : %.cpp
	g++ $(CPPFLAGS)  -g -c  $< -o $@ 