# Makefile

# target program

# default rule
a.out : main.o graph.o
	gcc main.o graph.o 

# compile source files into object files
main.o: main.c graph.h
	gcc -c main.c

graph.o: graph.c graph.h
	 gcc -c graph.c

# clean up build files
clean:
	rm -f *.o a.out

