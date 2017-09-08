/* Orphan State
2
Sujay Sanjay Mahadik*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	pid_t cpid;
	p = fork();
	if( p == 0 )
	{
        sleep(10);
		printf("\n This is child process. ");
		printf("\n\t My process id is : %d", getpid());
		printf("\n\t My Parent process id is : %d\n", getppid());
	}
	else
	{
		sleep(2);
		printf("\n My process id is : %d", getpid());
		printf("\n\t My Parent process id is : %d\n", getppid());
	}
return 0;
}
