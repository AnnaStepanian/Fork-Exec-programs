# Fork & Exec Programs

## Assignment 0: Multiple Fork Calls

### Objective
Understand the process hierarchy when multiple sequential fork syscalls are invoked.

### Description
This project contains three programs that demonstrate the behavior of multiple sequential `fork()` system calls and analyze the resulting process tree structure.

## Assignment 1: Simple Fork and Exec

### Objective
Understand the creation of a child process using fork and how to replace it with a new program using execl.

### Description
Demonstrates basic fork-exec pattern where a child process is created and then replaced with a new program using the `execl()` system call.

## Assignment 2: Multiple Forks and Execs

### Objective
Work with multiple child processes created using fork and run different commands using execl.

### Description
Creates multiple child processes, each executing different commands using `execl()`, demonstrating parallel execution of different programs.

## Programs Included:

### Assignment 0: Multiple Fork Programs

#### 1. `multiple_forks.c` - Basic Implementation
The original assignment implementation with three sequential fork calls.

**Features:**
- Calls three sequential fork() syscalls
- Tracks process hierarchy and PIDs
- Analyzes process tree structure
- Proper error handling and process synchronization

#### 2. `enhanced_forks.c` - Enhanced Analysis
An improved version with better process tracking and analysis.

**Features:**
- Level-based process tracking
- Detailed before/after fork analysis
- Process count tracking at each step
- Comprehensive final analysis

#### 3. `process_tree.c` - Visual Tree Structure
A visualization tool that shows the binary tree structure created by forks.

**Features:**
- Visual tree representation with indentation
- Clear parent-child relationships
- Step-by-step process creation visualization
- Summary statistics

### Assignment 1: Simple Fork and Exec

#### 4. `simple_fork_exec.c` - Basic Fork-Exec Pattern
Demonstrates the fundamental fork-exec pattern.

**Features:**
- Creates a single child process using fork()
- Child process executes 'ls -l' command using execl()
- Parent waits for child completion
- Proper error handling for both fork() and execl()

### Assignment 2: Multiple Forks and Execs

#### 5. `multiple_fork_exec.c` - Multiple Child Processes
Creates multiple child processes executing different commands.

**Features:**
- Creates two child processes using fork()
- First child executes 'ls -l' command
- Second child executes 'date' command
- Parent waits for both children to complete
- Demonstrates parallel execution of different programs

## Key Concepts Demonstrated:
- **Process Creation**: Each `fork()` creates an exact copy of the calling process
- **Process Hierarchy**: Parent-child relationships and process IDs (PID, PPID)
- **Binary Tree Structure**: With n forks, we get 2^n total processes
- **Process Synchronization**: Using `wait()` to prevent zombie processes
- **Error Handling**: Checking fork return values for failures
- **Process Replacement**: Using `execl()` to replace child process with new program
- **Parallel Execution**: Multiple child processes running different programs simultaneously
- **System Call Integration**: Combining fork() and exec() family functions

## Compilation and Execution:

```bash
# Compile all programs
make all

# Run basic implementation
make run

# Run enhanced analysis
make run-enhanced

# Run process tree visualization
make run-tree

# Run simple fork-exec example
make run-simple-exec

# Run multiple fork-exec example
make run-multiple-exec

# Clean up compiled files
make clean
```

## Expected Results:

### Process Count Formula:
- **1 fork**: 2 processes (1 parent + 1 child)
- **2 forks**: 4 processes (2 parents + 2 children)  
- **3 forks**: 8 processes (4 parents + 4 children)
- **n forks**: 2^n processes

### Process Tree Structure:
```
Original Process (PID: X)
├── Child 1 (from fork 1)
│   ├── Grandchild 1 (from fork 2)
│   │   └── Great-grandchild 1 (from fork 3)
│   └── Great-grandchild 2 (from fork 3)
├── Child 2 (from fork 2)
│   └── Great-grandchild 3 (from fork 3)
└── Child 3 (from fork 3)
```

## Learning Outcomes:
- Understanding how fork() creates process hierarchies
- Recognizing the exponential growth of processes with multiple forks
- Learning proper process management and synchronization
- Understanding parent-child process relationships
- Visualizing process tree structures
- Understanding process scheduling and execution order

## Shell Commands Demonstrated:
- `date` - Display current date and time
- `echo` - Print text to standard output
- `grep` - Search for patterns in files
- `ls` - List directory contents
- `make` - Build automation tool
