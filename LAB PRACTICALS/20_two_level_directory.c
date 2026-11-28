/* Lab program: 20_two_level_directory */
#include <stdio.h>
#include <string.h>
char users[10][20];
char files[10][10][20];
int fileCount[10] = {0};
int userCount = 0;
int main()
{
int choice, i, u, found;
char username[20], filename[20];
while (1)
{
printf("\n1.Create User\n2.Create File");
printf("\n3.Search File\n4.Display Directory");
printf("\n5.Exit\nEnter choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter username: ");
scanf("%s", username);
found = 0;
for (i = 0; i < userCount; i++)
if (strcmp(users[i], username) == 0)
found = 1;
if (!found && userCount < 10)
{
strcpy(users[userCount++], username);
printf("User directory created\n");
}
else
printf("User already exists or limit reached\n");
break;
case 2:
printf("Enter username: ");
scanf("%s", username);
u = -1;
for (i = 0; i < userCount; i++)
if (strcmp(users[i], username) == 0)
u = i;
if (u == -1)
{
printf("User not found\n");
break;
}
printf("Enter filename: ");
scanf("%s", filename);
if (fileCount[u] < 10)
{
strcpy(files[u][fileCount[u]++], filename);
printf("File created successfully\n");
}
else
printf("Directory is full\n");
break;
case 3:
printf("Enter username: ");
scanf("%s", username);
printf("Enter filename: ");
scanf("%s", filename);
found = 0;
for (i = 0; i < userCount; i++)
if (strcmp(users[i], username) == 0)
{
for (int j = 0; j < fileCount[i]; j++)
if (strcmp(files[i][j], filename) == 0)
found = 1;
}
if (found)
printf("File found\n");
else
printf("File not found\n");
break;
case 4:
for (i = 0; i < userCount; i++)
{
printf("\nUser: %s\n", users[i]);
for (int j = 0; j < fileCount[i]; j++)
printf("%s\n", files[i][j]);
}
break;
case 5:
return 0;
default:
printf("Invalid choice\n");
}
}
}
