SOURCES = Board.cpp Board.h
CPPC = g++
CPPFLAGS = -c -Wall -o2
LDLIBS = -pthread
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = Board

all: $(TARGET)

Board.o: Board.h

%.o: %.c
$(OBJECTS): Makefile

.cpp.o:
	$(CPPC) $(CPPFLAGS) $< -o $@$

$(TARGET): $(OBJECTS)
	$(CPPC) -o $@ $(OBJECTS) $(LDLIBS)

.PHONY: clean
clean:
	rm -f *~ *.o $(TARGET)