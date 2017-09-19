#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(){
	int pipe_path[2];
	int pipe_data[2];
	pid_t p;

	char path[] = "data.txt";
	char path_from_child[200];
	char data_from_parent[200];
	char data[200];
	char buff[200];
	FILE *fp;

	pipe(pipe_path);
	pipe(pipe_data);
	p = fork();
	if(p == 0){
		close(pipe_path[0]);
		write(pipe_path[1],path,sizeof(path));
		close(pipe_data[1]);
		read(pipe_data[0],data_from_parent, sizeof(buff));
		printf("...........CHILD AREA..........\n\nDate From Parent : : %s \n\n\n", data_from_parent );
	}
	else if(p > 0){
		close(pipe_path[1]);
		read(pipe_path[0],path_from_child, sizeof(path_from_child));
		printf("...........PARENT AREA.........\n\nPath from child : : %s \n\n\n", path_from_child );
		close(pipe_data[0]);
		fp = fopen(path_from_child, "r");
		fgets(buff, sizeof(buff), fp);
		fclose(fp);
		write(pipe_data[1],buff,sizeof(buff));

	}
	else{
		printf("Error\n");
	}
	return 0;
}