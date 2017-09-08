#include"stdio.h"
#include"pthread.h"
#include"ctype.h"
#include"unistd.h"
pthread_mutex_t w_lock;
pthread_mutex_t r_lock;
int readcnt=0;
FILE *fp;
void *writer(void *args){
	int pos=*(int*)args;
	char ch;
	pthread_mutex_lock(&w_lock);
	fp=fopen("test.txt","a");	
	if(fp==NULL)
		printf("\nUnable to open file\n");
	else{
		printf("\nThe thread no. %d is writing in file\n",pos);
		printf("\nEnter the text tobe entered\n");
		do{
			scanf(" %c",&ch);
			fputc(ch,fp);
		}while(isalnum(ch));
	}
	fclose(fp);
	sleep(1000);
	pthread_mutex_unlock(&w_lock);
	pthread_exit(NULL);
}

void *reader(void *args){
	int pos=*(int*)args;
	pthread_mutex_lock(&r_lock);
	readcnt++;
	char ch;
	if(readcnt==1)
		pthread_mutex_lock(&w_lock);
	pthread_mutex_unlock(&r_lock);
	fp=fopen("test.txt","r");	
	if(fp==NULL)
		printf("\nUnable to open file\n");
	else{
		printf("\nThe thread no. %d is reading the file\n",pos);
		printf("\nhe is reading..\n");
		ch = fgetc(fp);
		while (ch != EOF){
			printf ("%c", ch);
			ch = fgetc(fp);
		}
		pthread_mutex_lock(&r_lock);
		readcnt--;
		if(readcnt==0)
			pthread_mutex_unlock(&w_lock);
		pthread_mutex_unlock(&r_lock);	
		fclose(fp);
	}
	
	
	pthread_exit(NULL);
}

int main(){


	pthread_mutex_init(&w_lock,NULL);
	pthread_mutex_init(&r_lock,NULL);
	pthread_t threadarray[10];
	int bufferin[10];
	int i=0;
	int ch;
	printf("Read write?\n1:Write\n2:Read");
	scanf("%d",&ch);
	switch(ch){
		case 1:{
			
			pthread_create(threadarray + i, NULL , writer , (bufferin + i) );
			

		}
		case 2:{
			
			pthread_create(threadarray + i, NULL , reader , (bufferin + i) );
			
		}
		default:{
			printf("choose something\n");
		}
	}
	
	
	i = 0;
	for(;i<10;i++){
		pthread_join(*(threadarray+i) ,NULL);
	}
	
	pthread_mutex_destroy(&r_lock);
	pthread_mutex_destroy(&w_lock);
}