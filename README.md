# Fork & Exec Programs

Operating Systems assignments demonstrating process creation and management using `fork()` and `exec()` system calls.

## Assignments

### Assignment 0: Multiple Fork Calls
**Objective**: Understand process hierarchy with sequential fork calls
- **`multiple_forks`**: Basic implementation with 3 sequential forks (2³ = 8 processes)
- **`enhanced_forks`**: Advanced version with level tracking and detailed analysis
- **`process_tree`**: Visual tree representation of process hierarchy
- **Output**: Process IDs, parent-child relationships, and binary tree structure

### Assignment 1: Simple Fork and Exec
**Objective**: Basic fork-exec pattern with process replacement
- **`simple_fork_exec`**: Child runs `ls -l` command, parent waits
- **Output**: Directory listing + "Parent process done"

### Assignment 2: Multiple Fork and Exec
**Objective**: Parallel execution with multiple child processes
- **`multiple_fork_exec`**: Two children run `ls -l` and `date` commands
- **Output**: Directory listing + current date + "Parent process done"

### Assignment 3: Fork and Exec with Arguments
**Objective**: Pass arguments to external programs
- **`fork_exec_echo`**: Child runs `echo` with custom message
- **Output**: "Hello from the child process" + "Parent process done"

### Assignment 4: Fork and Exec with Command-Line Arguments
**Objective**: Advanced process execution with file processing
- **`fork_exec_grep`**: Child runs `grep` to search for "main" in `test.txt`
- **`test.txt`**: Sample file with text containing search term
- **Output**: Matching lines + "Parent process completed"

## Quick Start

```bash
# Build all programs
make all

# Run specific assignment
cd assignment0 && make run
cd assignment1 && make run
cd assignment2 && make run
cd assignment3 && make run
cd assignment4 && make run

# Clean up
make clean
```

## Key Concepts

- **Process Creation**: `fork()` creates exact copies (2^n processes after n forks)
- **Process Replacement**: `execl()` replaces child process with new program
- **Parallel Execution**: Multiple child processes running different commands
- **Argument Passing**: Using `execl()` to pass command-line arguments
- **Process Synchronization**: `wait()` for proper parent-child coordination

## Expected Results

- **Assignment 0**: 8 processes (2³) with clear hierarchy visualization
- **Assignment 1**: `ls` output + parent completion message
- **Assignment 2**: `ls` output + `date` output + parent completion message
- **Assignment 3**: Echo message + parent completion message
- **Assignment 4**: Grep results + parent completion message

All programs include proper error handling and clean, minimal output.