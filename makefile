CC = gcc

CCFLAGS = -Wall -ansi -pedantic

#Get header from paths defined
vpath %.h board

#Get c file from paths defined
vpath %.c board

DIRS = board
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o) board.o
TARGET = hexapawn

#=========Targets===========
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ 

.PHONY: clean

clean:
	@rm -f $(TARGET) $(OBJECTS) 
