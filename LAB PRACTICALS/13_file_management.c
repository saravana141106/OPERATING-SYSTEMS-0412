/* Lab program: 13_file_management */
#include <stdio.h>
#include <stdlib.h>
int main()
{
FILE *file;
char buffer[100];
/* Create and write to file */
file = fopen("example.txt", "w");
if (file == NULL)
{
printf("Error creating file.\n");
return 1;
}
fprintf(file, "Hello, World!\n");
fprintf(file, "This is a C file management example.\n");
fclose(file);
printf("File created and data written successfully.\n");
/* Open and read file */
file = fopen("example.txt", "r");
if (file == NULL)
{
printf("Error opening file.\n");
return 1;
}
printf("\nFile Contents:\n");
while (fgets(buffer, sizeof(buffer), file) != NULL)
{
printf("%s", buffer);
}
fclose(file);
printf("\nFile closed successfully.\n");
return 0;
}
