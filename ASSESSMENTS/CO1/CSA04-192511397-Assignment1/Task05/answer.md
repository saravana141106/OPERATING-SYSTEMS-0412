# Task 5 – System Calls

System calls are the controlled interface between user programs and kernel services. Typical categories:
- Process control: `fork`, `execve`, `wait`, `exit`
- File management: `open`, `read`, `write`, `close`, `stat`
- Device management: `ioctl`, device reads/writes
- Information maintenance: `getpid`, `uname`, `clock_gettime`
- Communication: `socket`, `send`, `recv`, pipes
- Protection: `chmod`, `setuid`, access checks

A call such as `read()` normally starts as a C-library wrapper. The wrapper places the system-call number and arguments in the ABI-defined registers/stack, executes the syscall/trap instruction, and switches from user mode to kernel mode. The kernel validates the descriptor and buffer, performs or schedules I/O, copies/ maps data as required, then returns a result or error and restores user mode. Arguments can be passed in registers, on the user stack, or through pointers to memory blocks.

`strace` can show calls, for example `strace -e trace=openat,read,write,close ./program`. The trace demonstrates the calls actually made by the process.

## Alternative: stdio versus direct system calls
`fopen`, `fread`, and `fwrite` are C-library interfaces. They typically buffer data in user space and invoke fewer kernel `read`/`write` calls. Direct `open`, `read`, and `write` expose the lower-level calls and require the application to handle partial transfers and errors. For a file of N bytes and buffer size B, an ideal sequential copy needs approximately `ceil(N/B)` read calls and `ceil(N/B)` write calls, plus open/close calls. Library buffering can reduce calls but consumes a user-space buffer of roughly B bytes per stream.
