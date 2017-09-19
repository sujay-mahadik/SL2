#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	int fd,fd1,ch,nos,i=0;
	int sroll, foundflag=0, foundroll;
	
	fd=open("/home/sujay/sl2/test/trialsyscall",O_CREAT|O_RDWR,0777);

	close(fd);
	if(fd==-1)
	{
		printf("Error opening");
	}

	struct stud
	{
		int roll;
		char name[10];
	}stud1, stud2, studsearch, studupdate;

	do{
		printf("\n\nEnter your choice\n1.Write\n2.Read\n3.Search\n4.Update\n5.Delete\n6.Exit");
		scanf("%d", &ch);
		switch(ch){
			case 1:
			fd=open("/home/sujay/sl2/test/trialsyscall", O_WRONLY | O_APPEND);
			printf("File open and ready for writing\n");
			printf("Enter roll\n");
			scanf("%d",&stud1.roll);
			printf("Enter Name\n");
			scanf("%s",stud1.name);
			write(fd,&stud1,sizeof(stud1));

			close(fd);
			break;

			case 2:
			fd=open("/home/sujay/sl2/test/trialsyscall",O_RDONLY);
			printf("File opened for reading\nContents of file\n");
			printf("Roll\tName\n");
			while(read(fd,&stud2,sizeof(stud2))){
				printf("%d\t",stud2.roll);
				printf("%s\t\n",stud2.name);
			}
			
			close(fd);
			break;

			case 3:

			fd=open("/home/sujay/sl2/test/trialsyscall",O_RDONLY);
			printf("File opened for searching\nEnter roll to be search\n");
			scanf("%d", &sroll);
			while(read(fd,&studsearch,sizeof(studsearch))){

				if (sroll==studsearch.roll)
				{

					printf("found");
					/* code */
				}
			}
			
			/*
			if (foundflag==1)
			{
				
				printf("%d\t",studr[foundroll+1].roll);
				printf("%s\t\n",studr[foundroll+1].name);
			}
			else{
				printf("Record not found\n");
			}
			*/
			close(fd);
			break;
			case 4:
			fd=open("/home/sujay/sl2/test/trialsyscall",O_RDWR);
			printf("File opened for updating\nEnter roll to be updated\n");
			scanf("%d", &sroll);
			while(read(fd,&studsearch,sizeof(studsearch))){
				if (sroll==studsearch.roll)
				{
					lseek(fd, 0-sizeof(studupdate), SEEK_CUR);
					printf("Enter New values\n");
					printf("Enter roll\n");
					scanf("%d",&studupdate.roll);
					printf("Enter Name\n");
					scanf("%s",studupdate.name);
					write(fd,&studupdate,sizeof(studupdate));
				}
			}


			break;
			close(fd);
			case 5:
			fd=open("/home/sujay/sl2/test/trialsyscall",O_RDWR);
			fd1=open("/home/sujay/sl2/test/temp",O_CREAT|O_RDWR,0777);
			printf("File opened for deleting\nEnter roll to be deleting\n");
			scanf("%d", &sroll);
			while(read(fd,&studsearch,sizeof(studsearch))){
				if (sroll==studsearch.roll)
				{
				}
				else{

					write(fd1,&studsearch,sizeof(studsearch));
				}
			}

			remove("trialsyscall");
			rename("temp", "trialsyscall");
			break;
			close(fd);

		}
	}while(ch<6);

	close(fd);
	return 0;


}