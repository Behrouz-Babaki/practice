.PHONEY : all

all : 10010

10010 : 10010.o
	g++ $< -o $@

%.o : %.cpp
	g++ -c $< -o $@