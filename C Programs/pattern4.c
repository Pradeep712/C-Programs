#include<stdio.h>
#include<conio.h>
#include<windows.h>
int main()
{
int pk,x;
for(x=0;x<255;x++){
printf("%d:%c\n",x,x);}
printf("Select any symbol:");
scanf("%d",&pk);
int a=1,i,j,k;
system("cls");
system("color 0F");
//Printing two upper right-angled triangles
for(i=0;i<11;i++)
{
for(j=0;j<=i;j++)
{
printf(" %c",pk);
a=0;
}
for(k=40;k>i*4;k--){
printf(" ");
}
for(j=0;j<=i;j++)
{
printf(" %c",pk);
a=0;
}
a=1;
printf("\n");
}
//Printing two lower right-angled triangles
for(i=0;i<10;i++)
{
for(j=9;j>=i;j--)
{
printf(" %c",pk);
a=0;
}
for(k=-3;k<=i*4;k++){
printf(" ");
}
for(j=9;j>=i;j--)
{
printf(" %c",pk);
a=0;}
a=1;
printf("\n");
}
printf("\n\n\n\n\t\t\t\t\t\t\t\tBy:Madan Lal");
getch();
}