# Operating Systems Assignment 3 – CO3
Student: H SARAVANA
Register Number: 192511397

## Environment
- Language: C
- Compiler: GCC (record the exact version on your Linux machine using `gcc --version`)
- Suggested compile flags: `gcc -std=c11 -Wall -Wextra`

## Tasks and execution
Each Task folder contains separate source files and comments with build/run instructions.
- Task01: static/dynamic linking and run-time loading. Build `libencrypt.so`, then `dynamic_app` with `-ldl`. Run from Task01 directory.
- Task02: paging address translation. `gcc -std=c11 -Wall -Wextra paging.c -o paging && ./paging`
- Task03: segmentation and base/limit validation. `gcc -std=c11 -Wall -Wextra segmentation.c -o segmentation && ./segmentation`
- Task04: effective access time calculation. `gcc -std=c11 -Wall -Wextra demand_paging.c -o demand_paging && ./demand_paging`
- Task05: FIFO, LRU and Optimal page replacement. `gcc -std=c11 -Wall -Wextra page_replacement.c -o page_replacement && ./page_replacement`
- Task06: RAID capacity calculation. `gcc -std=c11 -Wall -Wextra disk_capacity.c -o disk_capacity && ./disk_capacity`
- Task07: memory locking experiment and task memory budget. Compile each C file separately. `mlock()` may require privileges or an increased `RLIMIT_MEMLOCK`.

## Linux investigation commands
`ldd ./dynamic_app`, `size ./dynamic_app`, `/usr/bin/time -v ./program`, `cat /proc/<PID>/maps`, `lsblk`, `sudo fdisk -l`, and `swapon --show`.

## Submission notes
Add your own terminal screenshots and measured results. Record the exact Linux distribution, version, GCC version, and GitHub URL before submission. Commit each task separately. Do not claim that measurements were taken unless you actually ran the programs on your system.
