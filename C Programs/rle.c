#include <stdio.h>
#include <conio.h>

int main()
{
 int charcnt=0,dotcnt=0,commacnt=0,blankcnt=0,i, countA, countB;
 char str[125];

 printf("*****String Manipulations*****\n\n");
 printf("Enter a string\n\n");

 scanf("%[^'\n']s",str);

 printf("\n\nEntered String is \" %s \" \n",str);

 for(i=0;str[i]!='\0';i++)
 {

 // COUNTING EXCEPTION CHARS                         
 if(str[i]==' ')
    blankcnt++;

 if(str[i]=='.')
    dotcnt++;

 if(str[i]==',')
    commacnt++;

 if (str[i]=='A' || str[i]=='a')

  countA++;

      if (str[i]=='B' || str[i]=='b')

  countA++;

 }
 //PRINT RESULT OF COUNT
 charcnt=i;
 printf("\n\nTotal Characters : %d",charcnt);
 printf("\nTotal Blanks     : %d",blankcnt);
 printf("\nTotal Full stops : %d",dotcnt);
 printf("\nTotal Commas     : %d\n\n",commacnt);
 printf("A%d\n", countA);
}
