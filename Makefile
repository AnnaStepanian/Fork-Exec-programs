CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET1 = multiple_forks
TARGET2 = enhanced_forks
TARGET3 = process_tree
TARGET4 = simple_fork_exec
TARGET5 = multiple_fork_exec
SOURCE1 = multiple_forks.c
SOURCE2 = enhanced_forks.c
SOURCE3 = process_tree.c
SOURCE4 = simple_fork_exec.c
SOURCE5 = multiple_fork_exec.c

all: $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5)

$(TARGET1): $(SOURCE1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(SOURCE1)

$(TARGET2): $(SOURCE2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(SOURCE2)

$(TARGET3): $(SOURCE3)
	$(CC) $(CFLAGS) -o $(TARGET3) $(SOURCE3)

$(TARGET4): $(SOURCE4)
	$(CC) $(CFLAGS) -o $(TARGET4) $(SOURCE4)

$(TARGET5): $(SOURCE5)
	$(CC) $(CFLAGS) -o $(TARGET5) $(SOURCE5)

clean:
	rm -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5)

run: $(TARGET1)
	./$(TARGET1)

run-enhanced: $(TARGET2)
	./$(TARGET2)

run-tree: $(TARGET3)
	./$(TARGET3)

run-simple-exec: $(TARGET4)
	./$(TARGET4)

run-multiple-exec: $(TARGET5)
	./$(TARGET5)

.PHONY: all clean run run-enhanced run-tree run-simple-exec run-multiple-exec
