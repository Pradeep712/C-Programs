#include<stdio.h>
#include<conio.h>

void main()
{
int a[20],n,x,i,pos=0;
clrscr();
printf("Enter size of array:");
scanf("%d",&n);
printf("Enter the array in ascending order:\n");

for(i=0;i<n;++i)
scanf("%d",&a[i]);
printf("\nEnter element to insert:");
scanf("%d",&x);

for(i=0;i<n;++i)
if(a[i]<=x&&x<a[i+1])
{
pos=i+1;
break;
}

for(i=n+1;i>pos;--i)
a[i]=a[i-1];

a[pos]=x;
printf("\nArray after inserting element:");

for(i=0;i<n+1;i++)
printf("%d ",a[i]);
getch();
}
