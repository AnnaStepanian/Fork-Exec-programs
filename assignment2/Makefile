CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Assignment 2: Multiple Forks and Execs
TARGET = multiple_fork_exec
SOURCE = multiple_fork_exec.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
