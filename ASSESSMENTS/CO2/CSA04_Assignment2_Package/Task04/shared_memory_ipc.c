#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <semaphore.h>

typedef struct { int values[6]; int count; sem_t ready; } Shared;
int main(void){
    Shared *s=mmap(NULL,sizeof(Shared),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
    if(s==MAP_FAILED){perror("mmap");return 1;}
    sem_init(&s->ready,1,0);
    pid_t pid=fork();
    if(pid==0){
        sem_wait(&s->ready);
        int sum=0; for(int i=0;i<s->count;i++) sum+=s->values[i];
        printf("shared-memory analyser: count=%d average=%.1f\n",s->count,(double)sum/s->count);
        fflush(stdout); _exit(0);
    } else {
        int a[]={31,33,36,34,41,41}; s->count=6;
        for(int i=0;i<6;i++) s->values[i]=a[i];
        sem_post(&s->ready); wait(NULL);
        sem_destroy(&s->ready); munmap(s,sizeof(Shared));
        puts("sensor: done");
    }
    return 0;
}
