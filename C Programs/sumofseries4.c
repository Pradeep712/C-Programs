 #include<stdio.h>
#include<conio.h>


void main()
{
int i,n;
clrscr();
float sum=0,x,a=1;

printf("1/2+4/5+7/8+......");
printf("\n\nHow many terms(ex: 1,2,3...n)?");
scanf("%d",&n);


for(i=0;i<n;++i)
{
x=a/(a+1);
sum+=x;
a+=3;
}

printf("\nSum=%f",sum);
getch();
}
