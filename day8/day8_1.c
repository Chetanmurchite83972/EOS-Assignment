#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
 int main ()
 {
 int ret,i,s;
// for(int i=0;i<5;i++)
 {
 ret=fork();
 if(ret==0){
 printf("hello \n");
 sleep(5);
 _exit(0);
 }
}
for(int i=0;i<5;i++){
waitpid(-1,&s,0);
printf("child exit : %d \n",WEXITSTATUS(s));
}
 return 0;
 }
