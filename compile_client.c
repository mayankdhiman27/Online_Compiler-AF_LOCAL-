#include<stdio.h>
#include<stdlib.h>
#include<sys/un.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	int c_fd;
	c_fd=socket(AF_UNIX,SOCK_STREAM,0);
	struct sockaddr_un addr;
	addr.sun_family=AF_UNIX;
	strcpy(addr.sun_path,argv[1]);
	connect(c_fd,(struct sockaddr *)&addr,sizeof (addr));					
	int fd=open("/home/dmayank/Documents/code.txt",O_RDWR);
	int count=1,i=0;
	char *msg;
	char ch;
	while(count){
		count = read(fd, &ch,1);
			msg = realloc(msg,i+1);
			msg [i] = ch;
			i++;
		}
	int len;
	len=strlen(msg+1);
	write(c_fd,msg,len);
	return 0;
}


