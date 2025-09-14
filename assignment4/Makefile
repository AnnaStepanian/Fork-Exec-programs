CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = fork_exec_grep
SOURCE = fork_exec_grep.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
