# Charles Regan
# cwr2gb
# Due: 4/13/2015
# Makefile for CS 4102

# Defines the C++ compiler we'll be using
CXX	= clang++

# All of the .cpp files for our program
OFILES	= hw5.o Student.o Class.o

# This tells make to create a .o file from a .cpp file, using the
# defaults above (i.e. the CXX and CXXFLAGS macros)
.SUFFIXES: .o .cpp

# How to compile our final program.  Note that we do NOT specify an
# output executable name -- in order for this to work with the grading
# system, the file needs to be a.out (a.exe in Cygwin).
hw3:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
	mv a.out hw5

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	/bin/rm -f *.o *~

# We don't have any dependencies for this small program
