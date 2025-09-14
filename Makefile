# Main Makefile - Builds all assignments
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Assignment directories
ASSIGNMENT0 = assignment0
ASSIGNMENT1 = assignment1
ASSIGNMENT2 = assignment2
ASSIGNMENT4 = assignment4

all: assignment0 assignment1 assignment2 assignment4

assignment0:
	$(MAKE) -C $(ASSIGNMENT0) all

assignment1:
	$(MAKE) -C $(ASSIGNMENT1) all

assignment2:
	$(MAKE) -C $(ASSIGNMENT2) all

assignment4:
	$(MAKE) -C $(ASSIGNMENT4) all

clean:
	$(MAKE) -C $(ASSIGNMENT0) clean
	$(MAKE) -C $(ASSIGNMENT1) clean
	$(MAKE) -C $(ASSIGNMENT2) clean
	$(MAKE) -C $(ASSIGNMENT4) clean

# Run specific assignments
run-assignment0:
	$(MAKE) -C $(ASSIGNMENT0) run

run-assignment1:
	$(MAKE) -C $(ASSIGNMENT1) run

run-assignment2:
	$(MAKE) -C $(ASSIGNMENT2) run

run-assignment4:
	$(MAKE) -C $(ASSIGNMENT4) run

# Run all assignments
run-all: run-assignment0 run-assignment1 run-assignment2 run-assignment4

.PHONY: all assignment0 assignment1 assignment2 assignment4 clean run-assignment0 run-assignment1 run-assignment2 run-assignment4 run-all
