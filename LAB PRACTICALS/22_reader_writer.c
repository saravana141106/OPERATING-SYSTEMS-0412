/* Lab program: 22_reader_writer */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t mutex, wrt;
int readCount = 0;
int data = 0;
void *reader(void *arg)
{
int id = *(int *)arg;
sem_wait(&mutex);
readCount++;
if (readCount == 1)
sem_wait(&wrt);
sem_post(&mutex);
printf("Reader %d is reading data: %d\n", id, data);
sleep(1);
sem_wait(&mutex);
readCount--;
if (readCount == 0)
sem_post(&wrt);
sem_post(&mutex);
return NULL;
}
void *writer(void *arg)
{
int id = *(int *)arg;
sem_wait(&wrt);
data++;
printf("Writer %d is writing data: %d\n", id, data);
sleep(1);
sem_post(&wrt);
return NULL;
}
int main()
{
pthread_t r[2], w;
int a = 1, b = 2, c = 1;
sem_init(&mutex, 0, 1);
sem_init(&wrt, 0, 1);
pthread_create(&r[0], NULL, reader, &a);
pthread_create(&r[1], NULL, reader, &b);
pthread_create(&w, NULL, writer, &c);
pthread_join(r[0], NULL);
pthread_join(r[1], NULL);
pthread_join(w, NULL);
sem_destroy(&mutex);
sem_destroy(&wrt);
return 0;
}
