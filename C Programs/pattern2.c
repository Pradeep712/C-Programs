#include<stdio.h>

int main()
{
int i,j,k,n,a,b;
printf("How many lines?");
scanf("%d",&n);
n=n*2;

for(i=1;i<n;i+=2)
{
for(j=n-1;j>i;j-=2)
printf(" ");
for(k=1;k<=(i/2)+1;++k)
printf("%d",k);
for(k=i/2;k>=1;--k)
printf("%d",k);
printf("\n");
}
return 0;
}
