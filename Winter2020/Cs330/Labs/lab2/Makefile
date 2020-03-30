# leads comments in a line 
# Build all: default target
all : demo
CXX = gcc

# Separate compilation to build object files
main.o : main.c functions.h 
	$(CXX) -c -ggdb main.c

functions.o : functions.c functions.h 
	$(CXX) -c -ggdb functions.c

# linking
#demo is a target which depends upon main.o and greet.o 
#"$(CXX) main.o greet.o -o demo" is the command to produce the executable file
#You need to use a TAB before $(CXX) 
demo : main.o functions.o
	$(CXX) main.o functions.o -o demo

# Testing
check : all
	./demo

# Clean up all build targets so that one may get a clean build
clean :
	#core*
	rm -f *.o demo
	rm -f core*