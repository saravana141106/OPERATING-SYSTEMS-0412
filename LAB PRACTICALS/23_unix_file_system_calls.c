/* Lab program: 23_unix_file_system_calls */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
int fd;
char buffer[100] = {0};
char text[] = "UNIX File Management System";
fd = open("sample.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
if (fd < 0)
{
printf("File creation failed\n");
return 1;
}
write(fd, text, sizeof(text) - 1);
printf("Data written successfully\n");
lseek(fd, 0, SEEK_SET);
read(fd, buffer, sizeof(text) - 1);
printf("File Contents: %s\n", buffer);
close(fd);
printf("File closed successfully\n");
return 0;
}
