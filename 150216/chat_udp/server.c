#include "func.h"

int main(int argc,char** argv)
{
	int sfd=socket(AF_INET,SOCK_DGRAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in server;
	bzero(&server,sizeof(server));
	server.sin_family=AF_INET;
	server.sin_port=htons(atoi(argv[2]));
	server.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	ret=bind(sfd,(struct sockaddr *)&server,sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}
	printf("bind ok\n");
	char buf[128];
	struct sockaddr_in client;
	fd_set rdset;
	while(1)
	{	
		FD_ZERO(&rdset);
		FD_SET(0,&rdset);
		FD_SET(sfd,&rdset);
		ret=select(sfd+1,&rdset,NULL,NULL,NULL);
		if(ret>0)
		{
			if(FD_ISSET(sfd,&rdset))
			{
				bzero(buf,sizeof(buf));
				bzero(&client,sizeof(client));
				int clen=sizeof(struct sockaddr);
				ret=recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr *)&client,&clen);
				if(-1==ret)
				{
					perror("recvfrom");
					return -1;
				}
				printf("%s\n",buf);
			}
			if(FD_ISSET(0,&rdset))
			{
				bzero(buf,sizeof(buf));
				read(0,buf,sizeof(buf));
				ret=sendto(sfd,buf,strlen(buf)-1,0,(struct sockaddr *)&client,sizeof(struct sockaddr));
				if(-1==ret)
				{
					perror("sendto");
					return -1;
				}
			}
		}
	}
	close(sfd);
	return 0;
}

