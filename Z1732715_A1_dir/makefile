#
# PROGRAM:    Assign 1 
# PROGRAMMER: Samuel Piecz
# LOGON ID:   Z1732715
# DATE DUE:   9/06/19
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
Assign1: Assign1.o
	g++ $(CCFLAGS) -o Assign1 Assign1.o

# Rule to compile source code file to object code
Assign1.o: Assign1.cxx
	g++ $(CCFLAGS) -c Assign1.cxx

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Assign1
