//prints its own src code
#include<stdio.h>
#include<conio.h>
int main(int argc,char *argv[])
{
FILE *fp;
argv[0]=strcat(argv[0],".c"); //to add .c to the name of the file
fp=fopen(argv[0],"r"); //opens the file in read mode
char ch;
while(!feof(fp)) //till it reaches the end of file
{
fscanf(fp,"%c",&ch);
printf("%c",ch);
}//end while
getch();
return 0;
}//end main
