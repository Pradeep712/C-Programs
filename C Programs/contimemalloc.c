#include<stdio.h>
#include<conio.h>
#include<string.h>
void create();
int callrand();
void deletef();
void display();
struct fat
{
char name[15];
int size,start,end;
}x[51];
int no=1,used=0,m[1000]={0},tstart=0,low=0,high=0;
void main()
{ do{
int cho,i;
textcolor(GREEN);
clrscr();
x[0].size=0;
x[0].start=0;
x[0].end=0;
printf("\n\t\t\t CONTINOUS MEMORY ALLOCATION ");
printf("\n\n FILE MENU");
printf("\n\n 1.Create New File\n 2.Delete File\n 3.Display File\n 4.Exit");
printf("\n\n Enter Your option:");
scanf("%d",&cho);
while(cho<0 || cho>4)
{ printf("\n Enter Valid Option:");
scanf("%d",&cho);
};
switch(cho)
{
case 1 : clrscr();
printf("\n\t\tCreating New File..");
create();
break;
case 2 : clrscr();
printf("\n\t\tDeleting File..");
deletef();
break;
case 3 : clrscr();
printf("\n\t\tDisplaying File..");
display();
break;
case 4 : exit();
}
getch();
}while(1);
}
void create()
{
int cflag=0,i;
if(no<=50 && used<=1000)
{
printf("\nEnter the File Name:");
scanf("%s",&x[no].name);
printf("\nEnter the File Size:");
scanf("%d",&x[no].size);
if(x[no].size > 1000-used)
{
printf("\nDisk DO NOT have Enough MEMORY to save the file !");
}
else
{
used+=x[no].size;
low=x[no-1].end;
high=low+5;
do
{ cflag=0;
tstart=callrand();
for(i=tstart;i<tstart+x[no].size;i++)
{
if( m[i]==1)
{ cflag=1;
break;
}
}
if(cflag==0)
{
x[no].start=tstart;
x[no].end=tstart+x[no].size;
printf("\nFile Created Sucessfully.");
}
low+=10;
high+=10;
}while(high<1000-x[no].size && cflag==1);
for(i=x[no].start;i<x[no].end;i++)
m[i]=1;
}
no++;
}
else
printf("\nFiles or Memory limitation Exceeded !");
}
int callrand()
{
int z;
z= low+rand()%high;
return z;
}
void deletef()
{
if(no>1)
{ char na[15];
int i,j,found=-1;
printf("\nEnter the name of the file you want to delete:");
scanf("%s",&na);
for(i=0;i<=no;i++)
{
if(strcmp(na,x[i].name)==0)
{
found=i;
break;
}
}
if(found>0)
{
for(j=x[i].start;j<=x[i].end;j++)
{
m[j]=0;
}
x[i].name[0] = '/0';
used-=x[i].size;
low=x[i].start;
high=x[i].end;
printf("\n\tFile was Suceesfully deleted.");
printf("\n\tDisk space was increased by %d units.",x[i].size);
no--;
}
else
printf("\nNo File Found Named ' %s ' to Delete !",na);
}
else
printf("\nDisk is Empty !");
getch();
}
void display()
{ if(no>1)
{ char na[15];
int i,found=-1;;
printf("\nEnter the Name of File you Want to Display:");
scanf("%s",&na);
for(i=0;i<=no;i++)
{
if( strcmp(na,x[i].name) == 0 )
{ found=1;
printf("\n\nName of File: %s",x[i].name);
printf("\nMemory address Starting point: %d",x[i].start);
printf("\nMemory address Ending Point: %d",x[i].end);
printf("\nTotal size of File: %d units",x[i].size);
 
}
}
if(found==-1)
printf("\nNo File Found by Name ' %s ' in Memory !",na);
}
else
printf("\nDisk is Empty !");
getch();
}

