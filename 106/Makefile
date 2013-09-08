.PHONEY : all

all : 106

106 : 106.o
	g++ -g -pg $< -o $@

%.o : %.cpp
	g++ -c $< -o $@ 