# Task 8 – CPU States and Protection

User mode restricts applications from executing privileged instructions or directly accessing protected kernel memory. Kernel mode permits the OS to manage devices, page tables, interrupt controllers and scheduling. A hardware mode bit records the current privilege level. A system call or exception/trap transfers control to a kernel entry point; return-from-trap restores user mode.

Hardware interrupts notify the CPU of external events such as timer ticks or device completion. A trap/exception is synchronous with the current instruction (for example, invalid memory access or system call). A timer interrupt lets the scheduler regain control from a running task.

If a monitor application could disable interrupts without restriction, it could prevent the scheduler from running and delay or suppress an alarm-related task. User programs therefore cannot execute privileged interrupt-control instructions; only the kernel can manage interrupt masking, with carefully bounded critical sections.

Memory protection uses virtual address spaces and page-table permissions. The MMU checks every memory access; a process cannot read another process's pages unless the OS deliberately shares them.

## Alternative: polling instead of interrupts
With polling interval P, the worst-case detection delay due solely to polling is approximately P (plus processing/scheduling delay). Interrupt-driven detection instead depends on interrupt latency and higher-priority work. Polling repeatedly consumes CPU and energy even when no sensor event occurs; interrupts are more power-efficient for infrequent events. A validated hybrid design may poll at a controlled rate for diagnostics while using interrupts for urgent readings.
