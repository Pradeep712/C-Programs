#include<stdio.h>
#include<conio.h>
int main()
{
char ch[]="ram is a good boy";
int i;
for(i=0;i<20;i++)
{
if(ch[i]==' ')
continue;
else
printf("%c",ch[i]);
}
getch();
return 0;
}
