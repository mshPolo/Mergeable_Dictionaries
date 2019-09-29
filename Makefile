  TARGET = mergeable_dictionary.o
  SOURCE = main.c test.c 
  # Compiler
  CC = gcc

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  #CFLAGS  = -g -Wall
	CFLAGS  = -O3

  # the build target executable:
  TARGET = myprog

  all: $(TARGET)

  $(TARGET): $(TARGET).c
  	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

  clean:
  	$(RM) $(TARGET)