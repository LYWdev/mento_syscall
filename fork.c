#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<err.h>

static void child()
{	
	printf("Hello I'm child mypid is %d.\n",getpid());
	exit(EXIT_SUCCESS);
}

static void parent(pid_t pid_c)
{	
	printf("Hello I'm parent my pid is %d. || child pid : %d\n",getpid(), pid_c);
	exit(EXIT_SUCCESS);
}


int main(void)
{
	pid_t ret;
	ret= fork();
	if (ret == -1)
	{
		err(EXIT_FAILURE, "FORK90 FAILLED");
	}
	if (ret == 0)
	{
		child();
	}else{
		//parent process came here because fork returns the pid of newly created child process(> 1);
		parent(ret);
	}
	err(EXIT_FAILURE, "shouldn't reach here");

}
