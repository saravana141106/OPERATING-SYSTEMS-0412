/* Lab program: 03_producer_consumer_semaphores */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 5
int buffer[SIZE];
int item = 0;
sem_t empty, full, mutex;
void *producer(void *arg)
{
for (int i = 1; i<= 5; i++)
{
sem_wait(&empty);
sem_wait(&mutex);
buffer[item++] = i;
printf("Produced: %d\n", i);
sem_post(&mutex);
sem_post(&full);
}
return NULL;
}
void *consumer(void *arg)
{
for (int i = 1; i<= 5; i++)
{
sem_wait(&full);
sem_wait(&mutex);
int value = buffer[--item];
printf("Consumed: %d\n", value);
sem_post(&mutex);
sem_post(&empty);
}
return NULL;
}
int main()
{
pthread_t p, c;
sem_init(&empty, 0, SIZE);
sem_init(&full, 0, 0);
sem_init(&mutex, 0, 1);
pthread_create(&p, NULL, producer, NULL);
pthread_create(&c, NULL, consumer, NULL);
pthread_join(p, NULL);
pthread_join(c, NULL);
sem_destroy(&empty);
sem_destroy(&full);
sem_destroy(&mutex);
return 0;
}
