#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	int fd, retval;
	char buffer[] = "Hello World";
	
	fflush(stdin);
	retval = mkfifo("/tmp/myfifo",0666);
	fd = open("/tmp/myfifo",O_WRONLY);
	write(fd,buffer,sizeof(buffer));
	close(fd);
	printf("Information Sent");
	return 0;
}
