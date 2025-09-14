CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Assignment 1: Simple Fork and Exec
TARGET = simple_fork_exec
SOURCE = simple_fork_exec.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
