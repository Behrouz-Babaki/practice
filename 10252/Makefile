.PHONEY : all
all : 10252

10252 : 10252.o
	g++ $< -o $@

%.o : %.cpp
	g++ -c $< -o $@