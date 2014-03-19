.PHONY : all doc clean

JAVAC= javac
JAVA = java
sources = $(wildcard *.java)
classes = $(sources:.java=.class)
MAINNAME = Main

all: $(classes)

clean :
	@ rm -f *.class
	@ cd doc ; rm -f *~ ; rm -f -r html

%.class : %.java
	$(JAVAC) $<

doc : 
	cd doc; $(DOXY) dox.dxy

INPUT = input
INPUT2 = input2
test:	$(classes)
	@ echo "input:"
	@ cat $(INPUT)
	@ echo "output:"
	@ cat $(INPUT) | $(JAVA) $(MAINNAME)
	@ echo "input:"
	@ cat $(INPUT2)
	@ echo "output:"
	@ cat $(INPUT2) | $(JAVA) Main