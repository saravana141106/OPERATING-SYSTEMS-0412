#!/bin/sh
set -eu
gcc -std=c11 -Wall -Wextra -O2 -pthread measure_process_threads.c -o measure_process_threads
./measure_process_threads
gcc -std=c11 -Wall -Wextra -O2 copy_file.c -o copy_file
/usr/bin/time -v ./copy_file
if command -v strace >/dev/null 2>&1; then
  echo "For syscall counts, run: strace -c ./copy_file"
else
  echo "strace not installed; install it to collect kernel syscall counts."
fi
