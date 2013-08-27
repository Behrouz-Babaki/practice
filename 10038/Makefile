.PHONY: all

all : 10038

10038 : 10038.o
	g++ $< -o $@

%.o : %.cpp
	g++ -c $< -o $@