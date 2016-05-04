#
# This is for your executable
#
CFLAGS = -O3 -DNDEBUG
#CFLAGS = -Wall
#
# This is the setting for TA
#
# CFLAGS = -g -Wall -DTA_KB_SETTING
# CFLAGS = -O3 -DTA_KB_SETTING
# CFLAGS = -O3 -m32 -DTA_KB_SETTING

###############
# PHONY rules #
###############
.PHONY : insertionsort mer sel qui heap


ins : MAKEFLAGS = -Dinsertionsort $(CFLAGS)
mer: MAKEFLAGS = -Dmergesort $(CFLAGS)
sel: MAKEFLAGS = -Dselectionsort $(CFLGS)
qui: MAKEFLAGS = -Dquicksort $(CFLGS)
heap: MAKEFLAGS = -Dheapsort $(CFLGS)

ins :  clean insertionsort
mer:  clean mergesort
sel: clean selectionsort
qui: clean quicksort
heap: clean heapsort

##############
# Executable #
##############
insertionsort: 	main.o parser.o 
	g++ -o $@ $(MAKEFLAGS)  main.o parser.o 
	
#	strip $@

mergesort: main.o parser.o 
	g++ -o $@ $(MAKEFLAGS)  main.o parser.o 

selectionsort: main.o parser.o 
	g++ -o $@ $(MAKEFLAGS)  main.o parser.o 

quicksort: main.o parser.o 
	g++ -o $@ $(MAKEFLAGS)  main.o parser.o 

heapsort: main.o parser.o 
	g++ -o $@ $(MAKEFLAGS)  main.o parser.o 



################
# Object files #
################
main.o: main.cpp parser.h
	g++ -c $(MAKEFLAGS) main.cpp

parser.o: parser.cpp parser.h
	g++ -c $(MAKEFLAGS) parser.cpp



#######################
# No dependency rules #
#######################
clean:
	rm -f *.o main parser

#mergesort:
	
	
