#include<iostream.h>
#include<conio.h>


void main()
{
clrscr();
int y,f,i;
cout<<"Enter inches:";
cin>>i;


y=i/432;
i=i%432;
f=i/12;
i=i%12;


cout<<"Yard="<<y<<"\nFeet="<<f<<"\nInches="<<i;
getch();
}