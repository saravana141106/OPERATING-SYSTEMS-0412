# Task 10 – Measure and Compare

This task requires measurements on the student's own Linux system. No hardware measurements can be truthfully supplied in advance. Run the included scripts and paste actual results into the report.

Measure:
1. Copy-program system calls for buffer sizes 1, 512 and 4096 using `strace -c` or the program's internal read counter.
2. User and kernel CPU time using `/usr/bin/time -v`.
3. Time to create and reap 1,000 processes using `fork`.
4. Time to create and join 1,000 threads using pthreads.

Expected trends: larger buffers reduce read/write call counts; process creation is usually more expensive and uses more per-process kernel resources than thread creation; threads share an address space and therefore use less memory, but require synchronization and provide weaker isolation. Record CPU model, RAM, kernel version and compiler version with the results.

## Alternative: threads instead of processes
Threads commonly start faster because they share process resources, page tables and libraries. Processes provide stronger isolation and independent address spaces. The correct choice depends on the required failure containment: clinical command execution should generally remain process-isolated, while tightly controlled parallel work may use threads.
