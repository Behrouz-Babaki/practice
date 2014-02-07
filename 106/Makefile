.PHONEY : all clean

# -pg makes the compiler introduce profiling code into the target image (./106), which generates a statistics file (gmon.out) upon execution
CPPFLAGS += -pg -g

all : 106

106 : 106.o
	g++ $(CPPFLAGS)  $< -o $@

%.o : %.cpp
	g++ $(CPPFLAGS) -c  $< -o $@ 
clean:
	rm -f 106 106.o 
	rm -f *~
	rm -f 106.cpp.gcov 106.gcda 106.gcno gmon.out