#include <stdio.h>
#include <time.h>

int main()
{
	time_t timep;
	time(&timep);
	struct tm *ptm;
	ptm=gmtime(&timep);
	printf("%d:%d:%d,%d-%d-%d,%d,%d\n",ptm->tm_sec,ptm->tm_min,ptm->tm_hour,ptm->tm_mday,ptm->tm_mon+1,ptm->tm_year+1900,ptm->tm_wday,ptm->tm_yday);
	return 0;
}

