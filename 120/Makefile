CFLAGS	=	-std=c++0x

.PHONEY : all

all : 120

120 : 120.o
	g++ $< -o $@

%.o : %.cpp
	g++ -c $(CFLAGS) $< -o $@