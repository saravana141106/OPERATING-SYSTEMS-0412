/* Lab program: 10_turn_and_flag */
/* Q10: Process synchronization using Turn and Flag (Peterson's algorithm) */
#include <stdio.h>
#include <pthread.h>

volatile int flag[2] = {0, 0};
volatile int turn = 0;

void enter_critical(int self)
{
    int other = 1 - self;
    flag[self] = 1;          /* I want to enter */
    turn = other;            /* give the other process priority */
    while (flag[other] && turn == other)
        ;                    /* busy wait */
}

void exit_critical(int self)
{
    flag[self] = 0;
}

void *process(void *arg)
{
    int id = *(int *)arg;
    for (int i = 0; i < 2; i++) {
        enter_critical(id);
        printf("Process %d enters critical section\n", id);
        printf("Process %d exits critical section\n", id);
        exit_critical(id);
    }
    return NULL;
}

int main(void)
{
    pthread_t t[2];
    int id[2] = {0, 1};
    for (int i = 0; i < 2; i++)
        pthread_create(&t[i], NULL, process, &id[i]);
    for (int i = 0; i < 2; i++)
        pthread_join(t[i], NULL);
    return 0;
}
