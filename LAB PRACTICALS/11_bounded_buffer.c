/* Lab program: 11_bounded_buffer */
#include <stdio.h>
#define SIZE 3
int buffer[SIZE];
int in = 0, out = 0;
int count = 0;
void producer(int item)
{
if (count == SIZE)
{
printf("Buffer is full! Cannot produce %d\n", item);
return;
}
buffer[in] = item;
in = (in + 1) % SIZE;
count++;
printf("Producer produced: %d\n", item);
}
void consumer()
{
int item;
if (count == 0)
{
printf("Buffer is empty! Cannot consume\n");
return;
}
item = buffer[out];
out = (out + 1) % SIZE;
count--;
printf("Consumer consumed: %d\n", item);
}
int main()
{
producer(10);
producer(20);
producer(30);
producer(40);
consumer();
producer(40);
consumer();
consumer();
consumer();
return 0;
}
