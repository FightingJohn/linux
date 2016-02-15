#include"func.h"

int main(int argc,char** argv)
{
	int sfd=socket(AF_INET,SOCK_DGRAM,0);
	if(-1==sfd)
	{
		perror("socket");
		exit(-1);	
	}

	struct sockaddr_in saddr;
	bzero(&saddr,sizeof(saddr));
	saddr.sin_port=htons(8888);
	saddr.sin_addr.s_addr=INADDR_ANY;
	if(bind(sfd,(struct sockaddr*)&saddr,sizeof(struct sockaddr))==-1)
	{
		perror("bind");
		close(sfd);
		exit(-1);
	}
}
