.PHONEY : all

all : 850

850 : 850.o
	g++ $< -o $@

%.o : %.cpp
	g++ -c $< -o $@