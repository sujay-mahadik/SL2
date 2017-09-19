#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/stat.h>


int main()
{
	key_t key=100;
	char *shm,*s;
	int arr;
	int shmid = shmget(key,4096,IPC_CREAT | 0666);
	if(shmid<0)
	{
		printf("Error\n");
		exit(1);
	}

	else
	{
		printf("Success\n");
		printf("Shmid is %d\n",shmid );
		shm=(int*)shmat(shmid,NULL,0);
		printf("Enter data:");
		scanf("%d",&arr);
		*shm=arr;
		while(*shm!='a');
		

	}

	return 0;
}