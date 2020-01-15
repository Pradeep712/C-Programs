//adding two nos using cmd line arg
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
 
int main(int argc,char *argv[])
{
int sum=0,i;
//Compare if proper number of arguments have been entered
if(argc<3)
{
printf("Insufficient number of arguments...\n");
getch();
return 0;
}
 
//Add all the numbers entered using atoi function
for(i=1;i<argc;i++)
{
sum+=atoi(argv[i]);
}
 
//print the sum
printf("Ans=%d",sum);
getch();
}
