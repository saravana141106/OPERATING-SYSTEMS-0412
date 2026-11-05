#define _POSIX_C_SOURCE 200809L
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CAMERAS 64
#define WORK 1500000L

typedef struct { int start, end; } Range;
volatile unsigned long long total_plates = 0;
pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;

void process_camera(int camera) {
    unsigned long long local = 0;
    for(long i=0;i<WORK;i++) local += (unsigned long long)((i + camera) % 7 == 0);
    pthread_mutex_lock(&count_lock);
    total_plates += local;
    pthread_mutex_unlock(&count_lock);
}
void *worker(void *arg) {
    Range *r=(Range*)arg;
    for(int c=r->start;c<r->end;c++) process_camera(c);
    return NULL;
}
double now_sec(void){ struct timespec ts; clock_gettime(CLOCK_MONOTONIC,&ts); return ts.tv_sec+ts.tv_nsec/1e9; }
int main(void){
    int pools[]={1,4,8,16};
    for(int k=0;k<4;k++){
        int n=pools[k]; pthread_t th[16]; Range ranges[16];
        total_plates=0; double start=now_sec();
        for(int i=0;i<n;i++){
            ranges[i].start=i*CAMERAS/n;
            ranges[i].end=(i+1)*CAMERAS/n;
            if(pthread_create(&th[i],NULL,worker,&ranges[i])!=0){perror("pthread_create");return 1;}
        }
        for(int i=0;i<n;i++) pthread_join(th[i],NULL);
        double elapsed=now_sec()-start;
        printf("Workers=%d cameras=%d total=%llu time=%.6f sec\n",n,CAMERAS,total_plates,elapsed);
    }
    return 0;
}
