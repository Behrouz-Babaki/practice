.PHONEY : all

all : 10150

10150 : 10150.o
	g++ $< -o $@

%.o : %.cpp
	g++ -c $< -o $@