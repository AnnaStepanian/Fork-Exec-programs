# Fork & Exec Programs

Operating Systems assignments demonstrating process creation and management using `fork()` and `exec()` system calls.

## Structure

- **assignment0/**: Multiple fork programs (`multiple_forks`, `enhanced_forks`, `process_tree`)
- **assignment1/**: Simple fork-exec pattern (`simple_fork_exec`)
- **assignment2/**: Multiple fork-exec programs (`multiple_fork_exec`)

## Quick Start

```bash
# Build all programs
make all

# Run specific assignment
cd assignment0 && make run
cd assignment1 && make run
cd assignment2 && make run

# Clean up
make clean
```

## Key Concepts

- **Process Creation**: `fork()` creates exact copies of calling process
- **Process Hierarchy**: Parent-child relationships and PIDs
- **Binary Tree Structure**: n forks = 2^n total processes
- **Process Replacement**: `execl()` replaces child process with new program
- **Parallel Execution**: Multiple child processes running different programs

## Expected Results

- **1 fork**: 2 processes
- **2 forks**: 4 processes  
- **3 forks**: 8 processes
- **n forks**: 2^n processes

Each program demonstrates proper error handling, process synchronization with `wait()`, and clean process management.