#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<process.h>


char mat[3][3];
void table(void);            //function to print the table
void welcome(void);     //function for welcome screen

void main()
{
 welcome();
     A: clrscr();
 int i,j,m,n,sum=0;
 char ch;

 for(m=0;m<3;++m)
  for(n=0;n<3;++n)
   mat[m][n]='\0';
 table();

 while(sum<10)
 {
 //for player 1
 cout<<"Player 1 is'x'\nChoose the position:";
 cout<<"\nRow:";
 cin>>i;
 cout<<"Coloumn:";
 cin>>j;

//if position is wrong
 for(;i>3||i<1||j>3||j<1||('x'==mat[i-1][j-1]||'o'==mat[i-1][j-1]);)
 {
    cout<<"\nSorry!!!! wrong position,Choose the position again";
    cout<<"\nRow:";
    cin>>i;
    cout<<"Coloumn:";
    cin>>j;
 }
 mat[i-1][j-1]='x';
 sum++;

 //to check if player 1 wins or not
 if(mat[0][0]=='x'&&mat[0][0]==mat[0][1]&&mat[0][0]==mat[0][2])
 {
  table();
  cout<<"\nPlayer 1 wins.......!!!" ;
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[1][0]=='x'&&mat[1][0]==mat[1][1]&&mat[1][0]==mat[1][2])
 {
  table();
  cout<<"\nPlayer 1 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[2][0]=='x'&&mat[2][0]==mat[2][1]&&mat[2][0]==mat[2][2])
 {
  table();
  cout<<"\nPlayer 1 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[0][0]=='x'&&mat[0][0]==mat[1][0]&&mat[0][0]==mat[2][0])
 {
  table();
  cout<<"\nPlayer 1 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[0][1]=='x'&&mat[0][1]==mat[1][1]&&mat[0][1]==mat[2][1])
 {
  table();
  cout<<"\nPlayer 1 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[0][2]=='x'&&mat[0][2]==mat[1][2]&&mat[0][2]==mat[2][2])
 {
  table();
  cout<<"\nPlayer 1 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[0][0]=='x'&&mat[0][0]==mat[1][1]&&mat[0][0]==mat[2][2])
 {
  table();
  cout<<"\nPlayer 1 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[0][2]=='x'&&mat[0][2]==mat[1][1]&&mat[0][0]==mat[2][0])
 {
  table();
  cout<<"\nPlayer 1 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(sum==9) //to check the chances
 {
  table();
  cout<<"\n\tThe game is over.......no one wins...HaHaHa.....!!!";
  break;
 }
 //for player 2
 cout<<"\n\nPlayer 2 is'o'\nChoose the position:";
 cout<<"\nRow:";
 cin>>i;
 cout<<"Coloumn:";
 cin>>j;

 //if position is wrong
 for(;i>3||i<1||j>3||j<1||('x'==mat[i-1][j-1]||'o'==mat[i-1][j-1]);)
 {
    cout<<"\nSorry!!!! wrong position,Choose the position again";
    cout<<"\nRow:";
    cin>>i;
    cout<<"Coloumn:";
    cin>>j;
 }
 mat[i-1][j-1]='o';
 sum++;
 table();

 //to check player 2 wins or not
 if(mat[0][0]=='o'&&mat[0][0]==mat[0][1]&&mat[0][0]==mat[0][2])
 {
  cout<<"\nPlayer 2 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[1][0]=='o'&&mat[1][0]==mat[1][1]&&mat[1][0]==mat[1][2])
 {
  cout<<"\nPlayer 2 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[2][0]=='o'&&mat[2][0]==mat[2][1]&&mat[2][0]==mat[2][2])
 {
  cout<<"\nPlayer 2 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[0][0]=='o'&&mat[0][0]==mat[1][0]&&mat[0][0]==mat[2][0])
 {
  cout<<"\nPlayer 2 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[0][1]=='o'&&mat[0][1]==mat[1][1]&&mat[0][1]==mat[2][1])
 {
  cout<<"\nPlayer 2 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[0][2]=='o'&&mat[0][2]==mat[1][2]&&mat[0][2]==mat[2][2])
 {
  cout<<"\nPlayer 2 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[0][0]=='o'&&mat[0][0]==mat[1][1]&&mat[0][0]==mat[2][2])
 {
  cout<<"\nPlayer 2 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }

 if(mat[0][2]=='o'&&mat[0][2]==mat[1][1]&&mat[0][0]==mat[2][0])
 {
  cout<<"\nPlayer 2 wins.......!!!";
  cout<<"\nYou have played Great.....!!!";
  sleep(5);
  break;
 }
 }
 cout<<"\n\n\tWould you like to play more....?(y/n):";
 cin>>ch;
 if(ch=='y'||ch=='Y')
  goto A;
 else
 {
  cout<<"\n\n\tThanks for Playing.......:)";
  sleep(5);
  exit(0);
 }
}

void table()
{
 clrscr();
 cout<<"\n\n\t\t  1  2  3\n";
 cout<<"\t\t1  "<<mat[0][0]<<"|"<<mat[0][1]<<"|"<<mat[0][2];
 cout<<"\n\t\t  --|-|--";
 cout<<"\n\t\t2  "<<mat[1][0]<<"|"<<mat[1][1]<<"|"<<mat[1][2];
 cout<<"\n\t\t  --|-|--";
 cout<<"\n\t\t3  "<<mat[2][0]<<"|"<<mat[2][1]<<"|"<<mat[2][2]<<"\n\n";
}

void welcome()
{
 textmode(C80);
 textcolor(YELLOW);
 clrscr();

 cout<<"\n\n\n\n\n\t\t\t\tWelcome To";
 sleep(2);
 cout<<"\n\n\t\t\t\tTic-Tac-Toe";
 sleep(1);
 cout<<"\n\n\t\t\t\t   Game";
 sleep(1);
 cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue.....!!";
 getch();
}