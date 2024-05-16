#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<signal.h>

int main() {
	char ch = 'A';
	int ret,arr[5];
	struct sigaction sa;

	ret = pipe(arr);
	sigaction(SIGINT,&sa,NULL);
	int count = 0;

	while(1){
		write(arr[1],&ch,1);
		count++;
		printf("bytes written: %d\n",count);

	}

   void sigint_handler(int sig){
		close(arr[1]);
		close(arr[0]);
		_exit(1);
   	 }

	return 0;
}	
