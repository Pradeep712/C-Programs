#include<stdio.h>
#include<conio.h>

void main()
{
int i,j,n,d1=0,d2=0,a[5][5];
clrscr();
printf("Enter size of square matrix:");
scanf("%d",&n);
printf("Enter Elements of matrix:\n");

for(i=0;i<n;++i)
for(j=0;j<n;++j)
{
scanf("%d",&a[i][j]);
if(i==j)
d1+=a[i][j];
if((i+j)==(n-1))
d2+=a[i][j];
}

printf("\nFirst Digonal Sum=%d",d1);
printf("\nSecond Digonal Sum=%d",d2);
getch();
}
