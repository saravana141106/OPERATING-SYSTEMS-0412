# CSA04 Operating Systems – Assignment 1

**Student:** H SARAVANA  
**Register number:** 192511397  
**Repository name:** `CSA04-192511397-Assignment1`  
**GitHub URL:** Add your actual repository URL here after creating it.

## Environment (fill with the machine actually used)
- Linux distribution/version: **Record your actual output of** `cat /etc/os-release`
- Compiler/version: **Record your actual output of** `gcc --version`
- Compile command for POSIX programs: `gcc -std=c11 -Wall -Wextra -O2 -pthread file.c -o program`
- Run from the task folder: `./program`

## Folder contents
Task01–Task12 contain the written answer and relevant program or supporting material. The two assignment-specified complete-code programs are:
- `Task06/copy_file.c` – buffered `read()`/`write()` copy; prints EOF-inclusive read-call counts.
- `Task07/process_control.c` – `fork()`, `execlp()`, `waitpid()` and exit status.

Additional demonstration/measurement files are included where useful. Tasks 1–4, 8–9, 11–12 are design/evaluation tasks, not separate code-completion exercises in the PDF.

## Compile and execute
```sh
cd Task06
gcc -std=c11 -Wall -Wextra -O2 copy_file.c -o copy_file
./copy_file

cd ../Task07
gcc -std=c11 -Wall -Wextra process_control.c -o process_control
./process_control

cd ../Task10
gcc -std=c11 -Wall -Wextra -O2 -pthread measure_process_threads.c -o measure_process_threads
./measure_process_threads
```

## Important evidence to add after running
1. Add terminal screenshots and actual output files in the relevant task folder.
2. Run `strace -c ./copy_file` (and, if desired, `strace -e trace=openat,read,write,close ./system_calls_demo`) and save the output.
3. Record your actual OS, GCC version, CPU, RAM and measured timings in Task10.
4. Do not claim measurements until you have run them on your own Linux machine.
5. Create at least one meaningful Git commit per task. Do not upload everything as one final commit.
