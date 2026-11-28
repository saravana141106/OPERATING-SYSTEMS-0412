/* Lab program: 14_fifo_paging */
#include <stdio.h>
#define MAX_FRAMES 3
int main()
{
int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
int n = sizeof(pages) / sizeof(pages[0]);
int frames[MAX_FRAMES];
int pointer = 0;
int hits = 0, faults = 0;
int i, j, found;
for (i = 0; i < MAX_FRAMES; i++)
frames[i] = -1;
printf("FIFO PAGE REPLACEMENT\n");
printf("\nPage\tFrames\t\tStatus\n");
for (i = 0; i < n; i++)
{
found = 0;
for (j = 0; j < MAX_FRAMES; j++)
{
if (frames[j] == pages[i])
{
found = 1;
break;
}
}
if (found)
{
hits++;
printf("%d\t", pages[i]);
}
else
{
frames[pointer] = pages[i];
pointer = (pointer + 1) % MAX_FRAMES;
faults++;
printf("%d\t", pages[i]);
}
for (j = 0; j < MAX_FRAMES; j++)
{
if (frames[j] == -1)
printf("- ");
else
printf("%d ", frames[j]);
}
if (found)
printf("\tHit\n");
else
printf("\tPage Fault\n");
}
printf("\nTotal Page Hits: %d", hits);
printf("\nTotal Page Faults: %d\n", faults);
return 0;
}
