# Makefile for GSL C++ Program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -O2 -std=c++11

# Include directories 
INCLUDES = -I/usr/local/include

# Library directories 
LDFLAGS = -L/usr/local/lib

# Libraries to link against
LIBS = -lginac -lcln -lgsl -lgslcblas -lm

# Source file(s)
SOURCES = ytests.cpp

# Object file(s)
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name 
EXECUTABLE = y_dft
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean