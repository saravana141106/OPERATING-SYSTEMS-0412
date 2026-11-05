#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(void) {
    const char msg[] = "System calls connect user programs to the OS.\n";
    int fd = open("syscall-demo.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd < 0) { perror("open"); return 1; }
    if (write(fd, msg, strlen(msg)) < 0) { perror("write"); close(fd); return 1; }
    close(fd);
    fd = open("syscall-demo.txt", O_RDONLY);
    if (fd < 0) { perror("open"); return 1; }
    char buf[128]; ssize_t n = read(fd, buf, sizeof(buf));
    if (n < 0) { perror("read"); close(fd); return 1; }
    write(STDOUT_FILENO, buf, (size_t)n);
    close(fd);
    return 0;
}
