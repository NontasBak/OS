# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source files
SOURCES = program1.c program2.c program3.c program4.c program5.c

# Object files
OBJECTS = program1 program2 program3 program4 program5

# Output file
OUTPUT = output.txt

# Default target
all: $(OBJECTS)

# Targets for each file
program1: program1.c
	$(CC) $(CFLAGS) -o $@ $<

program2: program2.c
	$(CC) $(CFLAGS) -o $@ $<

program3: program3.c
	$(CC) $(CFLAGS) -o $@ $<

program4: program4.c
	$(CC) $(CFLAGS) -o $@ $<

program5: program5.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean target to remove compiled files
clean:
	rm -f $(OBJECTS) $(OUTPUT)
