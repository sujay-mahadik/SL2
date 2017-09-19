#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	
	int fd = open( "testfile.txt", O_WRONLY | O_CREAT );
	char msg[] = "msg in the file";
	if(fd < 0){
		printf("error\n");
	}
	else{
		printf("file opened\n");
		write(fd, &msg, sizeof(msg));
		close(fd);
		printf("written and closed\n");

	}

	fd = open("testfile.txt", O_RDONLY);
	char new_msg[] ="";
	if (fd != -1) {
		printf("in read\n");
		read(fd, &new_msg, sizeof(new_msg));
		printf("read\n");
		write(fd, &new_msg, sizeof(new_msg));
		printf("write \n");
		close(fd);
	}
/* code */
	return 0;
}