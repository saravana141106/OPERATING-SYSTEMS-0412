#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>
#define SIZE (16*1024*1024)
static double elapsed(struct timespec a, struct timespec b) {
    return (b.tv_sec-a.tv_sec)+(b.tv_nsec-a.tv_nsec)/1e9;
}
int main(void) {
    char *p=malloc(SIZE);
    if(!p) { perror("malloc"); return 1; }
    struct timespec a,b;
    clock_gettime(CLOCK_MONOTONIC,&a);
    volatile unsigned long sum=0;
    for(size_t i=0;i<SIZE;i+=4096) { p[i]=1; sum+=p[i]; }
    clock_gettime(CLOCK_MONOTONIC,&b);
    printf("Touch time without locking: %.6f s\n",elapsed(a,b));
    if(mlock(p,SIZE)!=0) perror("mlock (may require permission or RLIMIT_MEMLOCK)");
    clock_gettime(CLOCK_MONOTONIC,&a);
    for(size_t i=0;i<SIZE;i+=4096) { p[i]++; sum+=p[i]; }
    clock_gettime(CLOCK_MONOTONIC,&b);
    printf("Touch time after locking attempt: %.6f s\n",elapsed(a,b));
    printf("Checksum: %lu\n",sum);
    munlock(p,SIZE); free(p); return 0;
}
/* Compile: gcc -std=c11 -Wall -Wextra lock_memory.c -o lock_memory
   Run: ./lock_memory. Results depend on OS, permissions and system load. */
