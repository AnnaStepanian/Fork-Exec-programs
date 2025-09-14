CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Assignment 0: Multiple Fork Calls
TARGET1 = multiple_forks
TARGET2 = enhanced_forks
TARGET3 = process_tree
SOURCE1 = multiple_forks.c
SOURCE2 = enhanced_forks.c
SOURCE3 = process_tree.c

all: $(TARGET1) $(TARGET2) $(TARGET3)

$(TARGET1): $(SOURCE1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(SOURCE1)

$(TARGET2): $(SOURCE2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(SOURCE2)

$(TARGET3): $(SOURCE3)
	$(CC) $(CFLAGS) -o $(TARGET3) $(SOURCE3)

clean:
	rm -f $(TARGET1) $(TARGET2) $(TARGET3)

run: $(TARGET1)
	./$(TARGET1)

run-enhanced: $(TARGET2)
	./$(TARGET2)

run-tree: $(TARGET3)
	./$(TARGET3)

.PHONY: all clean run run-enhanced run-tree
