CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = fork_exec_echo
SOURCE = fork_exec_echo.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET) $(TARGET).dSYM -rf

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
