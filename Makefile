CPPC = g++
# -g  	- this flag adds debugging information to the executable file
# -wall - this flag is used to turn on most compiler warnings
# o2 	- this flag is used to turn on optimization
# Macro for the compiler flags 
CPPFLAGS = -c -Wall -o2
# Macro for the object files
OBJS = pieces.o board.o
LDLIBS = -pthread -lncurses

# *******************************************************************
# Targets to bring the executable up to date
all: main 

main: main.o $(OBJS)
	$(CPPC) main.o $(OBJS) $(LDLIBS) -o main

board.o: board.cpp
pieces.o: pieces.cpp coords.h

clean:
	rm -f *~ *.o main
