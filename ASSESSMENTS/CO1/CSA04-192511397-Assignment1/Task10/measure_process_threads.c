#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <pthread.h>

static double seconds(struct timespec a, struct timespec b) {
    return (b.tv_sec-a.tv_sec) + (b.tv_nsec-a.tv_nsec)/1e9;
}
static void *worker(void *p) { (void)p; return NULL; }

int main(void) {
    struct timespec a,b;
    clock_gettime(CLOCK_MONOTONIC,&a);
    for (int i=0;i<1000;i++) {
        pid_t p=fork();
        if (p==0) _exit(0);
        if (p<0) { perror("fork"); return 1; }
        if (waitpid(p,NULL,0)<0) { perror("waitpid"); return 1; }
    }
    clock_gettime(CLOCK_MONOTONIC,&b);
    printf("1000 fork+wait cycles: %.6f s\n",seconds(a,b));

    pthread_t t[1000];
    clock_gettime(CLOCK_MONOTONIC,&a);
    for (int i=0;i<1000;i++)
        if (pthread_create(&t[i],NULL,worker,NULL)!=0) { perror("pthread_create"); return 1; }
    for (int i=0;i<1000;i++) pthread_join(t[i],NULL);
    clock_gettime(CLOCK_MONOTONIC,&b);
    printf("1000 pthread create+join: %.6f s\n",seconds(a,b));
    return 0;
}
