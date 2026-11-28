/* Lab program: 15_fit_algorithms */
#include <stdio.h>
void firstFit(int blocks[], int m, int process[], int n)
{
int b[20], i, j;
for (i = 0; i < m; i++)
b[i] = blocks[i];
printf("\nFIRST FIT ALLOCATION\n");
for (i = 0; i < n; i++)
{
for (j = 0; j < m; j++)
{
if (b[j] >= process[i])
{
printf("Process %d allocated to Block %d\n",
i + 1, j + 1);
b[j] -= process[i];
break;
}
}
if (j == m)
printf("Process %d not allocated\n", i + 1);
}
}
void bestFit(int blocks[], int m, int process[], int n)
{
int b[20], i, j, best;
for (i = 0; i < m; i++)
b[i] = blocks[i];
printf("\nBEST FIT ALLOCATION\n");
for (i = 0; i < n; i++)
{
best = -1;
for (j = 0; j < m; j++)
{
if (b[j] >= process[i])
{
if (best == -1 || b[j] < b[best])
best = j;
}
}
if (best != -1)
{
printf("Process %d allocated to Block %d\n",
i + 1, best + 1);
b[best] -= process[i];
}
else
printf("Process %d not allocated\n", i + 1);
}
}
void worstFit(int blocks[], int m, int process[], int n)
{
int b[20], i, j, worst;
for (i = 0; i < m; i++)
b[i] = blocks[i];
printf("\nWORST FIT ALLOCATION\n");
for (i = 0; i < n; i++)
{
worst = -1;
for (j = 0; j < m; j++)
{
if (b[j] >= process[i])
{
if (worst == -1 || b[j] > b[worst])
worst = j;
}
}
if (worst != -1)
{
printf("Process %d allocated to Block %d\n",
i + 1, worst + 1);
b[worst] -= process[i];
}
else
printf("Process %d not allocated\n", i + 1);
}
}
int main()
{
int blocks[20], process[20];
int m, n, i;
printf("Enter number of memory blocks: ");
scanf("%d", &m);
printf("Enter memory block sizes:\n");
for (i = 0; i < m; i++)
scanf("%d", &blocks[i]);
printf("Enter number of processes: ");
scanf("%d", &n);
printf("Enter process sizes:\n");
for (i = 0; i < n; i++)
scanf("%d", &process[i]);
firstFit(blocks, m, process, n);
bestFit(blocks, m, process, n);
worstFit(blocks, m, process, n);
return 0;
}
