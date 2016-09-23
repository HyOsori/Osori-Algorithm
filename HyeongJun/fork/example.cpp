#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

	pid_t ret;
	ret = fork();
		if(ret>0){
			printf("parent process\n");
			ret = fork();
			if(ret>0){
				printf("child process1\n");
			}
			else if(ret ==0){
				printf("grandchild1\n");
			}
		}
		else if(ret==0){
			ret = fork();
			
			if(ret>0){
				printf("child process2\n");
			}
			else if(ret ==0){
				printf("grandchild2\n");
			}
		}

		else{
			printf("Error");
		}
	return 0;
}

