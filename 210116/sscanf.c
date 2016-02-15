#include<stdio.h>
#include<string.h>

int main(int argc,char* argv[])
{
	int a,b;
	char c[10],c1[10],c2[10];
	strcpy(c,"123");
	int ret;

	ret=sscanf(c,"%d",&a);
	printf("the ret is %d\n",ret);//返回被赋值的个数
	printf("the a is %d\n",a);

	//赋值多个数
	printf("------------------\n");
	strcpy(c,"123 456");
	ret=sscanf(c,"%d%d",&a,&b);
	printf("the ret is %d\n",ret);//返回被赋值的个数
	printf("the a is %d,%d\n",a,b);

	printf("------------------\n");
	//存在字符串
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	strcpy(c,"abc,efg");
	ret=sscanf(c,"%s,%s",c1,c2);
	printf("the ret is %d\n",ret);//返回被赋值的个数
	printf("the a is %s,%s\n",c1,c2);
	
	return 0;
}
