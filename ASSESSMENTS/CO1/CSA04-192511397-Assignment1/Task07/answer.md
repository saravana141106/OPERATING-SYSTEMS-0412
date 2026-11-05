# Task 7 – Process-Control System Calls

- `fork()` creates a child process with a separate process identity and a copy-on-write view of the parent's address space.
- `exec()` replaces the current process image with a new program; it does not create another process.
- `wait()`/`waitpid()` lets the parent collect a child's termination status and prevents a completed child remaining as a zombie.
- `exit()` terminates a process and makes its status available to the parent.

A shell parses a command, creates a child with `fork`, the child calls `exec` to run the requested program, and the parent calls `waitpid` when it should wait. The shell obtains the exit status from the wait status macros. A zombie is a terminated child whose parent has not yet collected its status. An orphan is a child whose parent exits first; it is adopted by a system reaper/init process.

`fork` followed by `exec` separates process creation from program loading and supports redirection, pipes, and shell setup between the two calls.

The supplied program in `Task07/process_control.c` implements both jobs and checks exit codes. `fflush(stdout)` before `fork()` prevents buffered text from being duplicated when both parent and child later flush copies of the same pre-fork stdio buffer. Without the flush, redirected output is commonly fully buffered, so the inherited buffer may be written by both processes. Changing `_exit(3)` to `exit(3)` runs stdio cleanup in the child and can flush inherited buffers; `_exit` terminates without flushing stdio buffers.

## Alternative: `posix_spawn` or threads
`posix_spawn()` can combine process creation and program execution behind one interface and may be more efficient for simple launches. Threads share an address space and can be cheaper to create, but they do not provide the same memory isolation as separate processes. A shell normally needs separate processes for independent external commands.
