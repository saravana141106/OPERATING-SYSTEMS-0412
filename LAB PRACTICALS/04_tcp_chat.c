/* Lab program: 04_tcp_chat */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>
int main()
{
int server_fd, client_fd, sock, n, i;
struct sockaddr_in addr;
char buf[1024];
const char *client_msgs[] = {"Hello", "How are you?", "bye"};
const char *server_msgs[] = {"Hi!", "I am fine"};
setvbuf(stdout, NULL, _IONBF, 0);
server_fd = socket(AF_INET, SOCK_STREAM, 0);
memset(&addr, 0, sizeof(addr));
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
addr.sin_port = htons(8080);
bind(server_fd, (struct sockaddr *)&addr, sizeof(addr));
listen(server_fd, 1);
if (fork() == 0)
{
/* CLIENT (child process) */
sock = socket(AF_INET, SOCK_STREAM, 0);
connect(sock, (struct sockaddr *)&addr, sizeof(addr));
for (i = 0; i < 3; i++)
{
send(sock, client_msgs[i], strlen(client_msgs[i]) + 1, 0);
if (strcmp(client_msgs[i], "bye") == 0)
break;
n = recv(sock, buf, sizeof(buf) - 1, 0);
if (n <= 0)
break;
buf[n] = '\0';
printf("Server: %s\n", buf);
}
close(sock);
return 0;
}
/* SERVER (parent process) */
client_fd = accept(server_fd, NULL, NULL);
printf("Client connected!\n");
for (i = 0; i < 3; i++)
{
n = recv(client_fd, buf, sizeof(buf) - 1, 0);
if (n <= 0)
break;
buf[n] = '\0';
printf("Client: %s\n", buf);
if (strcmp(buf, "bye") == 0)
break;
send(client_fd, server_msgs[i], strlen(server_msgs[i]) + 1, 0);
}
close(client_fd);
close(server_fd);
wait(NULL);
printf("Chat ended\n");
return 0;
}
