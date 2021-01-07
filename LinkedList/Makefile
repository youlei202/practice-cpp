# Compiler
CC=g++
CFLAGS=-Wall

# Objective file
TARGET=main

# Source file
SRCS=$(wildcard src/*.cc)
OBJS=$(SRCS:.cc=.o)

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

clean:
	rm -rf $(TARGET) $(OBJS)
