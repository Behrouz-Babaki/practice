.PHONY : all doc clean

DOXY = doxygen
MAINNAME = 108
CXX = g++
CPPFLAGS = -g

all : $(MAINNAME)

$(MAINNAME) : $(MAINNAME).o
	$(CXX) $(CPPFLAGS)  $< -o $@

%.o : %.cpp
	$(CXX) $(CPPFLAGS) -c  $< -o $@ 

doc : 
	cd doc; $(DOXY) dox.dxy

clean:
	@ rm -f *.o *~ 
	@ cd doc ; rm -f *~ ; rm -f -r html

INPUT = input
test:	$(MAINNAME)
	@ echo "input:"
	@ cat $(INPUT)
	@ echo "output:"
	@ cat $(INPUT) | ./$(MAINNAME)