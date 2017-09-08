//Sujay Sanjay Mahadik
//2
//sort 
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>


void bubble(int a[])
{
	int i=0,j=0,temp;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[i] < a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<5;i++)
		printf("%d, ",a[i]);
}


int main()
{
	char * const argv [] = {"/home/sujay/Desktop/sl2/print/code/binary.c", NULL};
	char * const envp []= {NULL};
	int a[5],i,j,low,mid,key,high,num;
	pid_t pid;
	//int status;
	printf("Enter The 5 Numbers To Be Sorted: ");
	for(i=0;i<5;i++)
		scanf(" %d", &a[i]);
	pid=fork();
	if(pid==0)
	{
			//sleep(20);
			//system("pstree -hp");
		printf("I Am Child Process\n");
		printf("Child Pid %d\n",getpid());
		printf("Parent Pid %d\n",getppid());
			//bubble1(a);
		execve("s",argv,envp);
	}
	else if(pid>0)
	{
		sleep(20);
			//system("ps -ax");
			//pid=wait(&status);
		printf("\nThe Pid Waited For Is %d\n",pid);
			//printf("The Status Is %d\n",status);
			/*if (WIFEXITED(status)) 
			{	
            	  printf("Exit Status =%d\n", WEXITSTATUS(status));
    		}*/
			//system("pstree -hp");
		printf("I Am Parent Process\n");
		printf("My Pid %d\n",getpid());
		printf("My Parent Pid %d\n",getppid());
		printf("\nThe Sorted Array Is: \n");
		bubble(a);
	}
	else
	{
		printf("Failed! Can't Create A Process\n");
	}
	return 0;
}
