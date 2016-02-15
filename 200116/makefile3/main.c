#include"mul.h"

int main(int argc,char *argv[])
{
	if(argc!=3){
		printf("argc error!");
		return 0;
	}

	int a,b;
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	printf("a*b=%d",mul(a,b));
	return 0;
}
