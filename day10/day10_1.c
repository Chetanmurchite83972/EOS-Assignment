#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/wait.h>

#define MQ_KEY		0x1234

typedef struct msg {
	long type;
	char data[32];
} msg_t;

int main() {
	int mqid, ret, s;
	// create message queue
	mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
	if(mqid < 0) {
		perror("msgget() failed");
		_exit(1);
	}

	ret = fork();
	if(ret == 0) {
		// child: initialize and send the message
		msg_t m1,m2;
		m1.type = 1;
		m2.type = 2;
		printf("sender: enter a 2 number: ");
		scanf("%s", m1.data);
		scanf("%s",m2.data);
		ret = msgsnd(mqid, &m1, sizeof(m1.data), 0);
		ret = msgsnd(mqid, &m2, sizeof(m2.data), 0);
		printf("sender: message sent: %d%d\n", ret,ret);
	}
	else {
		// parent: receive the message and print it
		msg_t m3;
		printf("receiver: waiting for the message...\n");
		m3 = m1 + m2;
		ret = msgrcv(mqid, &m3, sizeof(m3.data), 1, 0);
		printf("receiver: message received: %d -- %s\n", ret, m3.data);
	
		// wait for child and clean it up
		wait(&s);

		// destroy the message queue
			msgctl(mqid, IPC_RMID, NULL);
	}
	return 0;
}








