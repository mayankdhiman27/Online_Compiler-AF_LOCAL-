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
	char *buffer;
	FILE *fp,*f,*f2;
	int count=1,i=0;
	char ch;
	while(count){
		count=read(c_fd,&ch,1);
		buffer = realloc(buffer,i+ 1);
		buffer[i]=ch;
		++i;
		}
	fp=fopen("code1.c","w");
	fprintf(fp,"%s",buffer);
    	off_t position;
        int charsToDelete;
	charsToDelete = 1;
    	fseeko(fp,-charsToDelete,SEEK_END);
    	position = ftello(fp);
    	ftruncate(fileno(fp), position);
	f=popen("gcc -o /home/dmayank/Documents/code1 /home/dmayank/Documents/code1.c","r");
	sleep(2);
	system("/home/dmayank/Documents/code1 > dm.txt");
	f2=fopen("/home/dmayank/Documents/dm.txt","rb");
	char * buf;
	fseek(f2,0,SEEK_END);
	filelen=ftell(f2);
	rewind(f2);
	buffer=(char *)malloc((filelen+1)*sizeof(char));
	fread(buffer,filelen,1,f2);
	int len=strlen(buffer+1);
	write(c_fd,buffer,len);
	exit(0);
}


