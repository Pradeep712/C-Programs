#include<stdio.h>
#include<conio.h>

void main()
{
int a[50],*p,i,n;
clrscr();
p=a;
printf("Enter size of array:");
scanf("%d",&n);
printf("Enter elements of array:");

for(i=0;i<n;++i)
scanf("%d",p+i);

for(i=0;i<n;++i)
printf("%d ",*(p+i));
getch();
}