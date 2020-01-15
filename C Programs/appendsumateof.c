#include<stdio.h>
#include<conio.h>
#include<process.h>

main()
{
int a,i,n,sum=0;
FILE *fp;
clrscr();

//Writing numbers to the file
fp=fopen("DATA","w");
if(fp==NULL)
{
printf("File could not open!!");
exit(0);
}

printf("How many numbers?");
scanf("%d",&n);
printf("Enter numbers in the file:\n");

for(i=0;i<n;++i)
{
scanf("%d",&a);
putw(a,fp);
}
fclose(fp);

//Reading the file and doing sum
fp=fopen("DATA","r");
if(fp==NULL)
{
printf("File could not open!!");
exit(0);
}

while((a=getw(fp))!=EOF)
sum+=a;

fclose(fp);

//Appending sum to the file
fp=fopen("DATA","a");
if(fp==NULL)
{
printf("File could not open!!");
exit(0);
}

putw(sum,fp);
fclose(fp);

//Displaying file after append
fp=fopen("DATA","r");
if(fp==NULL)
{
printf("File could not open!!");
exit(0);
}

printf("\nFile after append:\n");
while((a=getw(fp))!=EOF)
printf("%d ",a);

fclose(fp);
getch();
}