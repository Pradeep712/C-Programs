#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int i,a=-1,b;
for(i=1;i<=40;i+=3)
{
     a*=-1;
     b=i;
     b*=a;
     cout<<b<<" ";
}
getch();
}
