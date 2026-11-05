# CSA04 Operating Systems – Assignment 2 (C02)

**Student:** Dharshini R D  
**Register number:** 192521277  
**Compiler:** GCC (record your installed version with `gcc --version`)  
**OS:** Linux (record distribution/version with `cat /etc/os-release`)

## Important note about the supplied question paper
Some source-code lines and the CPU-scheduling/Banker's input tables are unreadable in the supplied OCR text. The programs here are complete, runnable implementations. For Q2, the report explicitly states an illustrative four-job data set. For Q6, the standard five-process, three-resource Banker example is used. Replace these values if your original printed question contains a different readable table.

## Compile and run
From each task folder, compile with the command shown below. Add `-pthread` for thread/semaphore programs.

- Q1: `gcc -std=c11 -Wall -Wextra fork_process.c -o fork_process` then `./fork_process`
- Q2: `gcc -std=c11 -Wall -Wextra scheduling.c -o scheduling` then `./scheduling 3` (try `1`, `5`, and `20`)
- Q3: `gcc -std=c11 -Wall -Wextra -pthread thread_pool.c -o thread_pool` then `./thread_pool`
- Q4 pipe: `gcc -std=c11 -Wall -Wextra pipe_ipc.c -o pipe_ipc` then `./pipe_ipc`
- Q4 shared memory: `gcc -std=c11 -Wall -Wextra shared_memory_ipc.c -o shared_memory_ipc` then `./shared_memory_ipc`
- Q5: `gcc -std=c11 -Wall -Wextra -pthread bounded_buffer.c -o bounded_buffer` then `./bounded_buffer`
- Q6: `gcc -std=c11 -Wall -Wextra bankers.c -o bankers` then `./bankers`

## Folder contents
Each Task folder contains source code and an `output.txt` sample. Sample timings are machine-dependent; run on your own Linux machine and replace/add your terminal screenshots and measured values before submission.

## GitHub
Create repository `CSA04-192521277-Assignment2`. Commit each task separately. Add your faculty as collaborator if the repository is private. Paste the working repository URL into the report cover page and this README.
