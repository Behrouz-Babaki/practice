.PHONY: all

CXX = g++
CXXFLAGS = -g -lm -lcrypt -O2 -std=c++0x -pipe -DONLINE_JUDGE

all: checker checker2

checker : checker.o
	$(CXX) $(CXXFLAGS) $< -o $@

checker2 : checker2.o
	$(CXX) $(CXXFLAGS) $< -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	@ rm -f ./*~ ./*.o ./checker ./checker2

test : checker
	@ echo testing:
	@ ./checker ../input ../output 
