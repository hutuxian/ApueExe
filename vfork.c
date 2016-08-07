/*fork()和vfork的区别
 如果用fork，因为儿子进程等待两秒，所以父进程先输出完成，之后子进程才输出（运行的时候可以看到提示符先出来之后子进程的输出才出来
 如果用vfork，那么父进程会等待儿子进程先运行完成之后才继续运行;vfork的子进程和父进程共享地址空间，子进程中一定要执行exec或者exit，否则段错误*/
#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#define print(s) printf("%s\n",#s);
extern char **environ;
int main(){
	printf("output...\n");

	pid_t pid;
	pid = fork();
	//pid = vfork();
	if(pid == 0){
		sleep(2);
		printf("this is son...\n");
		//exit(0);
	}else if(pid > 0){
		printf("this is father...\n");
	}else{
		fprintf(stderr,"there is an error...");
	}
	return 0;
}
