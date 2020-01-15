#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>

void main()
{
textbackground(WHITE);
textcolor(RED);
     C: clrscr();

 char ch,a[20],ch2;
 int num=100,rnum,guess,count,ch1,c=0;
 cout<<"\n\t\t\t******************************"<<"\n\t\t\t******************************";
 cout<<"\n\t\t\t**                          **"<<"\n\t\t\t** Welcome To High/Low Game **"<<"\n\t\t\t** ________________________ **";
 cout<<"\n\t\t\t**                          **"<<"\n\t\t\t******************************"<<"\n\t\t\t******************************";
 cout<<"\n\n\n\n------------"<<"\n Main  Menu"<<"\n------------"<<"\n\n\n 1.Rules\n\n 2.Play\n\n 3.Exit"<<"\n\n Enter your choice(1-3):";
 cin>>ch1;

 switch(ch1)
 {
  case 1:
    {
    clrscr();
    cout<<"\n\n---------------------"<<"\n General Description"<<"\n---------------------";
    cout<<"\n\n1.The Computer picks a random number from 0 to 99.\n  You must try to guess the number.";
    cout<<"\n\n2.The Computer ask you to enter your guess.You have 8\n  chances to guess the number.";
    cout<<"\n\n3.The computer checks the number,if your guess is\n  less than computer's numer than it will show a message\n  that your guess is low and ask for higher number.";
    cout<<"\n\n4.If your guess is higher than the computer's number\n  than computer will show a message that your guess is high and\n  ask for lower number.";
    cout<<"\n\n5.If your guess is equal to the computer's number,than\n  computer will print a message congratulating you\n  and will ask you to play the game again or exit.";
    cout<<"\n\n6.If you are unable to guess the number than the computer\n  will a sorry message and ask you to play the game again or exit.";
    D: cout<<"\n\n\n  Press * to goto Main Menu:";
    cin>>ch2;
    if(ch2=='*')
    {
     ch2='#';
     goto C;
    }
    else
     goto D;
   }
    break;

 case 2:
  {
   clrscr();
   cout<<"\n\n\nEnter Your Name:";
   cin>>a;
   cout<<"\n\n";
   for(int i=0;i<=100;i+=20)
   {
    cout<<"Loading......."<<i<<"%\r";
    sleep(1);
   }
   cout<<"\n\nHi "<<a<<".........!!!!";

       A: if(c>0)
    clrscr();
   randomize();
   rnum=random(num);
   cout<<"\n\nEnter Your Guess:";
   cin>>guess;
   count=8;

     B: while(guess!=rnum)
        {
    count--;
    if(guess>rnum)
    {
     cout<<"\n\n"<<guess<<" is High....!!!!\a\a"<<"\n\nNow You Have "<<count<<" chance left";
     if(count==0)
     break;
     cout<<"\n\nEnter Your Guess Again:";
     cin>>guess;
     goto B;
    }
    if(guess<rnum)
    {
     cout<<"\n\n"<<guess<<" is Low...!!!\a\a"<<"\n\nNow You Have "<<count<<" chance left";
     if(count==0)
      break;
     cout<<"\n\nEnter Your Guess Again:";
     cin>>guess;
     goto B;
    }
   }
   if(guess==rnum)
   {
    cout<<"\n\n\t\tCongratulation "<<a<<" You Have Done IT.......!!!!!\a\a";
    switch(count)
    {
     case 7: cout<<"\n\nYour Score is 100 out of 100";
      break;
     case 6: cout<<"\n\nYour Score is 85 out of 100";
      break;
     case 5: cout<<"\n\nYour Score is 70 out of 100";
      break;
     case 4: cout<<"\n\nYour Score is 55 out of 100";
      break;
     case 3: cout<<"\n\nYour Score is 40 out of 100";
      break;
     case 2: cout<<"\n\nYour Score is 25 out of 100";
      break;
     case 1: cout<<"\n\nYour Score is 10 out of 100";
      break;
    }
   }
   else
    cout<<"\n\n\t\tSorry "<<a<<" Bad Luck......!!! Try Next Time\a\a\a";
   cout<<"\n\nWant to Play More(y/n):";
   cin>>ch;

   if(ch=='y'||ch=='Y')
   {
    c++;
    goto A;
   }
   else
    {
     cout<<"\n\n\n\n\t\t\t    @@@@@@@@ THANK YOU @@@@@@@@   \n\n";
     cout<<"================================================================================";

     cout<<"\a\a\n\n\t\t\t\t Special Thanks To\n\t\t\t\t___________________\n\n\t\t\t\t  Mrs.Rakhi Jain";
     cout<<"\n\n\n\n\t\t\t\t Game Developed By\n\t\t\t\t___________________\n\n\t\t\t\t  Neeraj Mishra";
     cout<<"\n\n================================================================================";
     delay(10000);
     exit(0);
    }
  }
   break;
 case 3:
  {
   cout<<"\n\n\n================================================================================";
    cout<<"\n\n\t\t\t\t Special Thanks To\n\t\t\t\t___________________\n\n\t\t\t\t  Mrs.Rakhi Jain";
    cout<<"\n\n\n\n\t\t\t\t Game Developed By\n\t\t\t\t___________________\n\n\t\t\t\t  Neeraj Mishra";
    cout<<"\n\n\n================================================================================";
    delay(10000);
    exit(0);

  }
 }
 getch();
}
