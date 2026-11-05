#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 5
#define ITEMS 20
#define PRODUCERS 4
#define CONSUMERS 4

int buffer[SIZE], in=0, out=0, consumed_sum=0, consumed_count=0;
sem_t empty_slots, full_slots;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

void *producer(void *arg){
    int id=*(int*)arg;
    for(int item=1;item<=ITEMS/PRODUCERS;item++){
        int value=id*(ITEMS/PRODUCERS)+item;
        sem_wait(&empty_slots);
        pthread_mutex_lock(&lock);
        buffer[in]=value; in=(in+1)%SIZE;
        pthread_mutex_unlock(&lock);
        sem_post(&full_slots);
    }
    return NULL;
}
void *consumer(void *arg){
    (void)arg;
    for(int i=0;i<ITEMS/CONSUMERS;i++){
        sem_wait(&full_slots);
        pthread_mutex_lock(&lock);
        int value=buffer[out]; out=(out+1)%SIZE;
        consumed_sum+=value; consumed_count++;
        pthread_mutex_unlock(&lock);
        sem_post(&empty_slots);
    }
    return NULL;
}
int main(void){
    pthread_t p[PRODUCERS],c[CONSUMERS]; int ids[PRODUCERS];
    sem_init(&empty_slots,0,SIZE); sem_init(&full_slots,0,0);
    for(int i=0;i<PRODUCERS;i++){ids[i]=i;pthread_create(&p[i],NULL,producer,&ids[i]);}
    for(int i=0;i<CONSUMERS;i++) pthread_create(&c[i],NULL,consumer,NULL);
    for(int i=0;i<PRODUCERS;i++) pthread_join(p[i],NULL);
    for(int i=0;i<CONSUMERS;i++) pthread_join(c[i],NULL);
    printf("Items consumed=%d, sum=%d, expected sum=%d\n",consumed_count,consumed_sum,ITEMS*(ITEMS+1)/2);
    sem_destroy(&empty_slots); sem_destroy(&full_slots);
    return 0;
}
