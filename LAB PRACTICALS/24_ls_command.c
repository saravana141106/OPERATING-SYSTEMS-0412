/* Lab program: 24_ls_command */
#include <stdio.h>
#include <dirent.h>
int main()
{
DIR *dir;
struct dirent *entry;
dir = opendir(".");
if (dir == NULL)
{
printf("Unable to open directory\n");
return 1;
}
printf("Files and Directories:\n");
while ((entry = readdir(dir)) != NULL)
{
if (entry->d_name[0] != '.')
printf("%s\n", entry->d_name);
}
closedir(dir);
return 0;
}
