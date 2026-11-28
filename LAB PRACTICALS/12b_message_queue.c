/* Lab program: 12b_message_queue */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct message
{
long type;
char text[100];
};
int main()
{
int msgid;
struct message msg;
msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
if (msgid == -1)
{
perror("msgget");
return 1;
}
msg.type = 1;
strcpy(msg.text, "Hello, message queue!");
if (msgsnd(msgid, &msg, sizeof(msg.text), 0) == -1)
{
perror("msgsnd");
msgctl(msgid, IPC_RMID, NULL);
return 1;
}
printf("Message sent: %s\n", msg.text);
if (msgrcv(msgid, &msg, sizeof(msg.text), 1, 0) == -1)
{
perror("msgrcv");
msgctl(msgid, IPC_RMID, NULL);
return 1;
}
printf("Message received: %s\n", msg.text);
msgctl(msgid, IPC_RMID, NULL);
return 0;
}
