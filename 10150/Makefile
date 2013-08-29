.PHONEY : all

all : 10150 10150_verbose.a

10150 : 10150.o
	g++ $< -o $@

%.a : %.o
	g++ $< -o $@

%.o : %.cpp
	g++ -c $< -o $@