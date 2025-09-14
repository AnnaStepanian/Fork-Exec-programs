# Main Makefile - Builds all assignments
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Assignment directories
ASSIGNMENT0 = assignment0
ASSIGNMENT1 = assignment1
ASSIGNMENT2 = assignment2

all: assignment0 assignment1 assignment2

assignment0:
	$(MAKE) -C $(ASSIGNMENT0) all

assignment1:
	$(MAKE) -C $(ASSIGNMENT1) all

assignment2:
	$(MAKE) -C $(ASSIGNMENT2) all

clean:
	$(MAKE) -C $(ASSIGNMENT0) clean
	$(MAKE) -C $(ASSIGNMENT1) clean
	$(MAKE) -C $(ASSIGNMENT2) clean

# Run specific assignments
run-assignment0:
	$(MAKE) -C $(ASSIGNMENT0) run

run-assignment1:
	$(MAKE) -C $(ASSIGNMENT1) run

run-assignment2:
	$(MAKE) -C $(ASSIGNMENT2) run

# Run all assignments
run-all: run-assignment0 run-assignment1 run-assignment2

.PHONY: all assignment0 assignment1 assignment2 clean run-assignment0 run-assignment1 run-assignment2 run-all
