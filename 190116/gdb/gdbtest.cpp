#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void MyPrint(const char *pszSrc)
{
   printf("The string is %s\n", pszSrc);
}

void MyPrint2(const char *pszSrc)
{
    char *pszRev;
    int i,iLen;
    iLen=strlen(pszSrc);
    pszRev=(char *)malloc(iLen+1);
    for(i=0;i<iLen;i++)
        pszRev[i]=pszSrc[iLen-i];  //经过调试，发现此处应为：[iLen-i-1]
    pszRev[iLen]='\0';
    printf("The revert string is:%s\n",pszRev);
    free(pszRev);
}
