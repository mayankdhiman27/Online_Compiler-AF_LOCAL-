#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/un.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
int main(int argc,char * argv[])
{
	int s_fd;
	s_fd=socket(AF_LOCAL,SOCK_STREAM,0);
	struct sockaddr_un addr;
	addr.sun_family=AF_LOCAL;
	strcpy(addr.sun_path,argv[1]);
	bind(s_fd,(struct sockaddr *)&addr,sizeof(addr));
	listen(s_fd,5);
	int c_fd;
	struct sockaddr_un c_addr;
	socklen_t size_addr;
	c_fd=accept(s_fd,(struct sockaddr *)&c_addr,&size_addr);
	int count=1,i=0;
	char ch;
	char msg[1000];
	while(count){
		count=read(c_fd,&ch,1);
		msg[i]=ch;
		i++;
		}
	printf("%s",msg);
	printf("\n");
	exit(0);
}

