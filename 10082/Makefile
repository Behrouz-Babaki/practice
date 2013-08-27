.PHONY: all

all : 10082

10082 : 10082.o
	g++ $< -o $@

%.o : %.cpp
	g++ -c $< -o $@