#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<err.h>
static void child()
{
  char *args[] = { "/bin/echo", "hello", NULL};
  printf("I'm child!! my pid is %d\n",getpid());
  fflush(stdout);
  execve("bin/echo", args, NULL);
}