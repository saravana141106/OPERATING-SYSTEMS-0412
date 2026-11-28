/* Lab program: 19_single_level_directory */
#include <stdio.h>
#include <string.h>
char files[20][30];
int count = 0;
int main()
{
int choice, i, found;
char name[30];
while (1)
{
printf("\n1.Create File\n2.Delete File");
printf("\n3.Search File\n4.Display Files");
printf("\n5.Exit\nEnter choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter file name: ");
scanf("%s", name);
found = 0;
for (i = 0; i < count; i++)
if (strcmp(files[i], name) == 0)
found = 1;
if (found)
printf("File already exists\n");
else if (count < 20)
{
strcpy(files[count++], name);
printf("File created successfully\n");
}
else
printf("Directory is full\n");
break;
case 2:
printf("Enter file name: ");
scanf("%s", name);
found = 0;
for (i = 0; i < count; i++)
{
if (strcmp(files[i], name) == 0)
{
for (int j = i; j < count - 1; j++)
strcpy(files[j], files[j + 1]);
count--;
found = 1;
printf("File deleted successfully\n");
break;
}
}
if (!found)
printf("File not found\n");
break;
case 3:
printf("Enter file name: ");
scanf("%s", name);
found = 0;
for (i = 0; i < count; i++)
if (strcmp(files[i], name) == 0)
found = 1;
if (found)
printf("File found\n");
else
printf("File not found\n");
break;
case 4:
printf("\nFiles in Directory:\n");
for (i = 0; i < count; i++)
printf("%s\n", files[i]);
break;
case 5:
return 0;
default:
printf("Invalid choice\n");
}
}
}
