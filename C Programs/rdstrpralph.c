#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
int i,j,n,ch1,ch2;
char a[50],temp;
clrscr();
printf("Enter any string:");
scanf("%s",a);
n=strlen(a);

for(i=1;i<n;++i)
for(j=0;j<(n-i);++j)
{
ch1=a[j];
ch2=a[j+1];
if(ch1>ch2)
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}

printf("String after arranging %s",a);
getch();
}