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
	sfd=socket(AF_INET,SOCK_STREAM,0);//生成一个套接口描述符
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in server_addr;
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family=AF_INET;//采用ipv4协议
	server_addr.sin_port = htons(atoi(argv[2]));//端口号
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);//用来将IP地址字符串转换成网络所使用的二进制数字
	int ret;
	ret=bind(sfd,(struct sockaddr*)&server_addr,sizeof(struct sockaddr));//使套接口与指定的端口号和IP地址相关联	
	if(-1==ret)
	{
		perror("bind");
		close(sfd);
		return -1;
	}
	ret=listen(sfd,NUM);//使服务器的这个端口和IP处于监听状态，等待网络中某个客户机的连接请求
	if(-1==ret)
	{
		perror("listen");
		close(sfd);
		return -1;
	}
	struct sockaddr_in client_addr;
	bzero(&client_addr,sizeof(client_addr));
	int length=sizeof(client_addr);
	int newfd;
	char buf[128];
	while(1)
	{
		newfd=accept(sfd,(struct sockaddr*)&client_addr,&length);//接受远程计算机的连接请求，建立起与客户机之间的通信连接
		if(-1==newfd)
		{
			perror("accept");
			close(sfd);
			return -1;
		}
		printf("connect success,client IP=%s,client port=%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
		bzero(buf,sizeof(buf));
		ret=recv(newfd,buf,sizeof(buf),0);//用新的套接字来接收远端主机传来的数据，并把数据存到由参数buf指向的内存空间	
		if(ret >0)
		{
			printf("the message is %s\n",buf);
		}
		bzero(buf,sizeof(buf));
		strcpy(buf,"hello,client.I'm the server");
		ret=send(newfd,buf,strlen(buf),0);//用新的套接字发送数据给指定的远端主机
		if(-1==ret)
		{
			perror("send");
			close(newfd);
			close(sfd);//让数据写回磁盘，并释放该文件所占用的资源
			return -1;
		}
	}
	return 0;
}
	
