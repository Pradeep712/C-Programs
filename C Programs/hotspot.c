/* This Program set, start and stop hotspot in windows 7.*/
 
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int t=0;
void frame(void);
void main()
{
start0:
clrscr();
int c;
textcolor(5+t);
gotoxy(40,8);
cprintf("Please Run this program as");
gotoxy(40,9);
cprintf("Administrator.");
gotoxy(40,13);
cprintf("Right Click on Program-> ");
gotoxy(40,14);
cprintf("Run as Administrator.");
 
start:
frame();
cprintf("Enter choice : ");
gotoxy(27,23);
scanf("%d",&c);
textcolor(5+t);
switch(c)
{
case 1: //set hotspot
system("netsh wlan set hostednetwork mode=allow ssid=Hotspot key=vgecvgec keyusage=persistent");
clrscr();
gotoxy(40,8);
cprintf("Done !!! Hotspot Set !!!");
gotoxy(40,9);
cprintf("Now you can start Hotspot");
gotoxy(40,11);
cprintf("Name : Hotspot");
gotoxy(40,12);
cprintf("Password : vgecvgec");
gotoxy(40,14);
cprintf("To start Hotspot Use option 2");
goto start;
case 2: //start hotspot
system("netsh wlan start hostednetwork");
clrscr();
gotoxy(40,8);
cprintf("Started Successfully.");
gotoxy(40,11);
cprintf("Name : Hotspot");
gotoxy(40,12);
cprintf("Password : vgecvgec");
gotoxy(40,20);
cprintf("Not Started ?");
gotoxy(40,22);
cprintf("Please See Help.");
goto start;
case 3: //stop hotspot
system("netsh wlan stop hostednetwork");
clrscr();
gotoxy(40,8);
cprintf("Stopped Successfully.");
goto start;
case 4:
t++;
if(t>=4){t=0;}
goto start0;
case 5:
clrscr();
gotoxy(39,8);
cprintf("Follow Steps to use Hotspot :");
gotoxy(39,10);
cprintf("1. Run Program as Administrator.");
gotoxy(39,11);
cprintf("2. Set up Hotspot If using");
gotoxy(39,12);
cprintf(" first time");
gotoxy(39,13);
cprintf("3. Start Hotspot and Use.");
gotoxy(39,14);
cprintf("4. stop Hotspot");
gotoxy(40,17);
cprintf("Name : Hotspot");
gotoxy(40,18);
cprintf("Password : vgecvgec");
gotoxy(39,21);
cprintf("For more enter 51.");
goto start;
 
case 51:
clrscr();
gotoxy(39,8);
cprintf("How to connect Another Net");
gotoxy(39,9);
cprintf("Connection with Hotspot.");
gotoxy(39,11);
cprintf("1. Open Network and sharing");
gotoxy(39,12);
cprintf(" centre->Change Adpter");
gotoxy(39,13);
cprintf(" Settings->");
gotoxy(39,14);
cprintf("2. Now Right Click on Adpter");
gotoxy(39,15);
cprintf(" which has internet.");
gotoxy(39,16);
cprintf("3. In sharing tab, check both");
gotoxy(39,17);
cprintf(" box. Now Open settings and");
gotoxy(39,18);
cprintf(" check all boxes.");
gotoxy(39,21);
cprintf("For more queries Contact Me.");
gotoxy(39,22);
cprintf("See About.");
goto start;
 
case 6:
clrscr();
gotoxy(40,7);
cprintf("=============================");
gotoxy(40,8);
cprintf(" Bhargav K Patel ");
gotoxy(40,9);
cprintf("=============================");
gotoxy(40,13);
cprintf("Email : ");
gotoxy(40,15);
cprintf(" bhargav079@gmail.com");
gotoxy(40,18);
cprintf("Facebok : ");
gotoxy(40,20);
cprintf(" www.facebook.com/olodoio");
goto start;
case 7:
exit (0);
default:
clrscr();
gotoxy(40,8);
cprintf("Invalid Choice.");
goto start;
}
}
 
void frame(void)
{
textcolor(2+t);
for(int i=5;i<=70;i++)
{
gotoxy(i,1);
cprintf("%c",220);
}
 
for(i=5;i<=70;i++)
{
gotoxy(i,24);
cprintf("%c",220);
}
for(i=2;i<=24;i++)
{
gotoxy(5,i);
cprintf("%c",219);
}
for(i=2;i<=24;i++)
{
gotoxy(70,i);
cprintf("%c",219);
}
textcolor(1+t);
 
for(i=6;i<=69;i++)
{
gotoxy(i,5);
cprintf("%c",254);
}
 
for(i=6;i<=34;i++)
{
gotoxy(i,21);
cprintf("%c",22);
}
textcolor(9+t);
for(i=6;i<=23;i++)
{
gotoxy(35,i);
cprintf("%c%c",204,185);
}
textcolor(12-t);
gotoxy(25,3);
cprintf("Hotspot for Windows 7");
textcolor(14-t);
gotoxy(8,7);
cprintf("1. Set for first use");
gotoxy(8,9);
cprintf("2. Start Hotspot");
gotoxy(8,11);
cprintf("3. Stop Hotspot");
gotoxy(8,13);
cprintf("4. Change Color theme");
gotoxy(8,15);
cprintf("5. Help");
gotoxy(8,17);
cprintf("6. About");
gotoxy(8,19);
cprintf("7. Exit");
gotoxy(8,23);
textcolor(24-t);
return;
}