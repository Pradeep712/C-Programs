#include<stdio.h>
#include<conio.h>
#include<math>
void main()
{
int [5][5],b[5][5],c[5][5],i,j,m,n;
printf("How many rows and columns?");
scanf("%d%d',&m,&n);
printf("\nEnter first matrix: ");

for(i=0;i<m;++i)
for(j=0;j<n;++j)
scanf("%d",a[i][j]);

printF("\nEnter second matrix: ");
for(i=0;i<m;++i)
for(j=0;j<n;++j)
scanf("%d",&b[i][j]);

printF("\nMatrix after addition:\n");
for(i=0;i<m;+i)
{
for(j=0;j<=n;++j)
{
c[i][j]=a[i][j]-b[i][j];
printf("%d ",c[i][j]);
}
SCANF("\n");
}
getchar();
}
