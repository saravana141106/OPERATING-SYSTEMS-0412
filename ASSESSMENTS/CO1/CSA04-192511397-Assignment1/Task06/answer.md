# Task 6 – Cost of System Calls

A system call costs more than an ordinary function call because execution crosses the user/kernel protection boundary, validates arguments and permissions, may acquire kernel locks, and can block or trigger device I/O. The exact cost depends on CPU, kernel, cache state and whether I/O is cached.

For a file of size N and buffer B, an ideal copy performs approximately `ceil(N/B)` reads and `ceil(N/B)` writes. Increasing B generally reduces call count, but consumes more memory and has diminishing returns once the buffer is large relative to storage/network characteristics.

The assignment's 10,000-byte test has expected read counts:
- B=1: 10,001 read calls (including final EOF read)
- B=512: 21 read calls
- B=4096: 4 read calls

The program in `Task06/copy_file.c` records read-call counts and elapsed time for each buffer size. Run it on Linux and record actual timings; timings vary by machine and cache state. For more reliable comparisons, repeat runs and report median values. `strace -c` can independently count system calls.

## Alternative: memory-mapped I/O
`mmap` maps file pages into virtual memory; the program accesses them as memory rather than issuing an explicit read/write for each chunk. It can reduce explicit syscall frequency and copying, but page faults still cause kernel work and dirty pages must be written back. Mapping a very large file does not require all pages to be resident simultaneously, but virtual address space and page-cache pressure matter.
