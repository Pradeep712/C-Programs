#include<iostream.h>
#include<conio.h>

#define CUBE(x) (x*x*x)

void main()
{
clrscr();
int n,cube;
cout<<"Enter a number:";
cin>>n;

cube=CUBE(n);
cout<<"Cube="<<cube;
getch();
}
