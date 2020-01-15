#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
FILE *fp1,*fp2;
char ch,*f1,*f2;
clrscr();

printf("Enter source file name(ex:source.txt): ");
scanf("%s",f1);
printf("Enter destination file name(ex:destination.txt): ");
scanf("%s",f2);

fp1=fopen(f1,"r");
fp2=fopen(f2,"w");

if(fp1==NULL||fp2==NULL)
{
printf("File could not open!!");
exit(0);
}

while((ch=getc(fp1))!=EOF)
putc(ch,fp2);

fclose(fp1);
fclose(fp2);
}
