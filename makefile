# Name of the executable
EXEC = battaglia_navale

# Compiler
CC = g++

# Compilation flags
CFLAGS = -Wall -Wextra -std=c++11

# List of source files
SRCS = main.cc gioco.cc servizio.cc inser_e_iniz.cc dati.cc

# List of object files (each .cc will be compiled into a .o)
OBJS = $(SRCS:.cc=.o)

# List of files to clean
CLEANFILES = $(OBJS) $(EXEC)

# Default rule: create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Rule for compiling .cc files into .o
%.o: %.cc dati.h
	$(CC) $(CFLAGS) -c $< -o $@

# Cleans up object files and the executable
clean:
ifeq ($(OS),Windows_NT)
	del /q $(CLEANFILES)
else
	rm -f $(CLEANFILES)
endif

# Rule to run the program (optional)
run: $(EXEC)
	./$(EXEC)
