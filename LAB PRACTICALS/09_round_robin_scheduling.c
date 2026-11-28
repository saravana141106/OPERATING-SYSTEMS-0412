/* Lab program: 09_round_robin_scheduling */
#include <stdio.h>
int main()
{
int n, bt[10], rem[10], wt[10], tat[10];
int quantum, time = 0, done;
float avgwt = 0, avgtat = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
for (int i = 0; i< n; i++)
{
printf("Enter burst time for P%d: ", i + 1);
scanf("%d", &bt[i]);
rem[i] = bt[i];
}
printf("Enter time quantum: ");
scanf("%d", &quantum);
do
{
done = 1;
for (int i = 0; i< n; i++)
{
if (rem[i] > 0)
{
done = 0;
if (rem[i] > quantum)
{
time += quantum;
rem[i] -= quantum;
}
else
{
time += rem[i];
wt[i] = time - bt[i];
rem[i] = 0;
}
}
}
} while (!done);
printf("\nProcess\tBT\tWT\tTAT\n");
for (int i = 0; i< n; i++)
{
tat[i] = bt[i] + wt[i];
printf("P%d\t%d\t%d\t%d\n",
i + 1, bt[i], wt[i], tat[i]);
avgwt += wt[i];
avgtat += tat[i];
}
printf("Average Waiting Time = %.2f\n", avgwt / n);
printf("Average Turnaround Time = %.2f\n", avgtat / n);
return 0;
}
