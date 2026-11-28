# CSA0412 Operating Systems – Lab Programs

| File | Lab question |
|---|---|
| 01_process_creation_fork.c | 1. Create a process with fork(); display PID and parent PID |
| 02_file_copy.c | 2. Copy the content of one file to another |
| 03_producer_consumer_semaphores.c | 3. Producer–consumer using semaphores |
| 04_tcp_chat.c | 4. Client–server chat using TCP sockets |
| 05_multithreading.c | 5. Multithreading with pthreads |
| 06_fcfs_scheduling.c | 6. FCFS CPU scheduling |
| 07_sjf_smallest_first.c | 7. Scheduling by smallest execution time |
| 08_priority_scheduling.c | 8. Scheduling by highest priority |
| 09_round_robin_scheduling.c | 9. Round Robin scheduling (code in lab doc is Round Robin) |
| 10_turn_and_flag.c | 10. Process synchronization – Turn and Flag (Peterson's algorithm) |
| 11_bounded_buffer.c | 11. Bounded buffer problem |
| 12a_shared_memory.c | 12A. IPC using shared memory |
| 12b_message_queue.c | 12B. IPC using message queue |
| 13_file_management.c | 13. File management operations |
| 14_fifo_paging.c | 14. FIFO page replacement |
| 15_fit_algorithms.c | 15. First fit, best fit, worst fit |
| 16_fcfs_disk_scheduling.c | 16. FCFS disk scheduling |
| 17_bankers_algorithm.c | 17. Banker's algorithm |
| 18_dining_philosophers.c | 18. Dining philosophers |
| 19_single_level_directory.c | 19. Single-level directory |
| 20_two_level_directory.c | 20. Two-level directory |
| 21_random_access_file.c | 21. Random access file for employee records |
| 22_reader_writer.c | 22. Reader–writer problem |
| 23_unix_file_system_calls.c | 23. UNIX file system calls |
| 24_ls_command.c | 24. Simulate ls |
| 25_grep_command.c | 25. Simulate grep |

Compile on Linux: `gcc <file>.c -o <name> -pthread`
Note: 04_tcp_chat.c uses fork() and POSIX sockets (Linux/Unix).
