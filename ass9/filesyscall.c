#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
struct student
{
	char name[20];
	int roll;
}s[10];
int main()
{
	int fd = open( "testfile", O_APPEND | O_CREAT, 0666 );
	char msg[] = "msginthefile";
	if(fd < 0){
		printf("error\n");
	}
	else{
		write(fd, msg, sizeof(msg));
		close(fd);
	}

	fd = open("testfile", O_RDONLY);
	char new_msg[500];
	if (fd != -1) {
		printf("in read\n");
		read(fd, new_msg, sizeof(new_msg));
		printf("%s\n", new_msg);
		close(fd);
	}
/* code */
	return 0;
}