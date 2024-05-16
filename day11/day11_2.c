#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main() {

	int ret,r,num1,num2,arr1[2],arr2[2],res,s;
	ret = pipe(arr1);
	ret = pipe(arr2);

	ret = fork();
	if(ret == 0){
		close(arr1[0]);
		close(arr2[1]);
		printf("child enter two number: ");	
		scanf("%d%d",&num1,&num2);
		write(arr1[1],&num1,sizeof(num1));
		write(arr1[1],&num2,sizeof(num2));

		read(arr2[0],&res,sizeof(res));
		printf("result: %d\n",res);

		close(arr2[0]);
		close(arr1[1]);
	}

	else{
		close(arr1[1]);
		close(arr2[0]);
		read(arr1[0],&num1,sizeof(num1));
		read(arr1[0],&num2,sizeof(num2));

		r = num1 + num2;

		write(arr2[1],&r,sizeof(r));

		close(arr2[1]);
		close(arr1[0]);
		waitpid(-1,&s,0);
	}
	return 0;
} 
