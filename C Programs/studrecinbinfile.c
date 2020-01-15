#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct student
{
int rollno;
char *name;
int m1,m2,m3;
}s1;

void main()
{
FILE *fp;
clrscr();
fp=fopen("Record.dat","wb");	//opening binary file in writing mode
if(fp==NULL)
{
printf("File could not open");
exit(0);
}

printf("Enter student details\n");
printf("Roll No:");
scanf("%d",&s1.rollno);
printf("Name:");
scanf("%s",s1.name);
printf("Marks in three subjects:");
scanf("%d%d%d",&s1.m1,&s1.m2,&s1.m3);

fwrite(&s1,sizeof(s1),1,fp);	    //writing to binary file
printf("\nRecord has been added successfully...!!");
fclose(fp);
getch();
}
