#include<stdio.h>
#include<conio.h>

void main()
{
int a,b,hcf,lcm,max,min,r;
clrscr();
printf("Enter two numbers:");
scanf("%d%d",&a,&b);

if(a>b)
{
max=a;
min=b;
}
else
if(b>a)
{
max=b;
min=a;
}

if(a==b)
hcf=a;
else
{
do
{
r=max%min;
max=min;
min=r;
}while(r!=0);
hcf=max;
}

lcm=(a*b)/hcf;
printf("\nLCM=%d\nHCF=%d",lcm,hcf);
getch();
}