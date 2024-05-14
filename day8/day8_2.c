#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int ret1,ret2,ret3,s1,s2,s3;
	ret1=fork();
	if(ret1==0){
		ret2=fork();
		if (ret2==0){
			ret3=fork();
			if(ret3 ==0){
printf("sunbeam\n");
	_exit(0);
	}
	printf("infotech\n");
	waitpid(ret3,&s3,0);
	_exit(0);
	}
	printf("pune\n");
	waitpid(ret2,&s2,0);
	_exit(0);
	}
	printf("desd\n");
	waitpid(ret1,&s1,0);
			return 0;
		}
