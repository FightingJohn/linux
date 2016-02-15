#include "func.h"
#define NUM 10
int main(int argc,char* argv[])
{
	if(argc !=3)
	{
		printf("error args\n");
		return -1;
	}
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in server_addr;
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	ret=bind(sfd,(struct sockaddr*)&server_addr,sizeof(struct sockaddr));	
	if(-1==ret)
	{
		perror("bind");
		close(sfd);
		return -1;
	}
	ret=listen(sfd,NUM);
	if(-1==ret)
	{
		perror("listen");
		close(sfd);
		return -1;
	}
	struct sockaddr_in client_addr;
	bzero(&client_addr,sizeof(client_addr));
	int length=sizeof(client_addr);
	int newfd=-1;
	char buf[128];
	fd_set rdset;
	printf("sfd is %d\n",sfd);
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(0,&rdset);
		FD_SET(sfd,&rdset);
		if(newfd >0)
		{
			FD_SET(newfd,&rdset);
		}
		ret=select(NUM+4,&rdset,NULL,NULL,NULL);//多路选择
		if(ret >0)
		{
			if(FD_ISSET(sfd,&rdset))
			{
				newfd=accept(sfd,(struct sockaddr*)&client_addr,&length);//
				if(-1==newfd)
				{
					perror("accept");
					close(sfd);
					return -1;
				}	
				printf("newfd is %d\n",newfd);
				printf("connect success,client IP=%s,client port=%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
			}
			if((newfd >0) && FD_ISSET(newfd,&rdset))
			{	
				bzero(buf,sizeof(buf));
				ret=recv(newfd,buf,sizeof(buf),0);	
				if(ret >0)
				{
					printf("%s\n",buf);
				}
			}
			if(FD_ISSET(0,&rdset))
			{
				bzero(buf,sizeof(buf));
				read(0,buf,sizeof(buf));
				ret=send(newfd,buf,strlen(buf)-1,0);
				if(-1==ret)
				{
					perror("send");
					close(newfd);
					close(sfd);
					return -1;
				}
			}
		}
	}
	return 0;
}
	
