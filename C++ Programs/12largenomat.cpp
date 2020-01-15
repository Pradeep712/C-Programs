#include<iostream.h>
#include<conio.h>

void main()
{
clrscr();
int a[5][5],big1,big2,n,m,i,j;
cout<<"Enter no of rows and columns(max 5):";
cin>>m>>n;
cout<<"Enter the array:\n";
for(i=0;i<m;i++)
for(j=0;j<n;++j)
cin>>a[i][j];

big1=a[0][0];
for(i=0;i<m;++i)
for(j=0;j<n;++j)
{
if(a[i][j]>big1)
big1=a[i][j];
}

big2=a[0][0];
for(i=0;i<m;++i)
for(j=0;j<n;++j)
{
if(a[i][j]>big2&&a[i][j]<big1)
big2=a[i][j];
}

cout<<"\n\nLargest number:"<<big1;
cout<<"\nSecond largest number:"<<big2;
getch();
}