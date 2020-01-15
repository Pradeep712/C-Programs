#include<stdio.h>
#include<conio.h>

void main()
{
int i,j,m,n,d1=0,d2=0,a[5][5];
clrscr();
printf("How many rows and columns:");
scanf("%d%d",&m,&n);
printf("Enter matrix elements:\n");

for(i=0;i<m;++i)
for(j=0;j<n;++j)
{
scanf("%d",&a[i][j]);
if(j>i)
d1+=a[i][j];
else
if(i>j)
d2+=a[i][j];
}

printf("Sum of elements above the digonal=%d\n",d1);
printf("Sum of elements below the digonal=%d",d2);
getch();
}
