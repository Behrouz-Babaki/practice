.PHONY : all doc clean

DOXY = doxygen
MAINNAME = 103

all : $(MAINNAME)

$(MAINNAME) : $(MAINNAME).o
	g++ $(CPPFLAGS) -g  $< -o $@

%.o : %.cpp
	g++ $(CPPFLAGS)  -g -c  $< -o $@ 

doc : 
	cd doc; $(DOXY) dox.dxy

clean:
	@ rm -f *.o *~ 
	@ cd doc ; rm -f *~ ; rm -f -r html

compare: compare.cpp
	g++ $@.cpp -o $@