string cancatenation w/o strcat()
#include<stdio.h>
#include<conio.h>
#include<string.h>
void concatenate(char a[],char b[]){
 char c[strlen(a)+strlen(b)]; //size of c is sum of a and b
 int i=0,j=0;
 while(i<strlen(a)) //adds the first string to c
 c[i++]=a[i];
 while(j<strlen(b)) //adds the second string to c
 c[i++]=b[j++];
 c[i]='\0'; //finally add the null character
 printf("After concatenation:\n");
 printf("Value = %s",c);
}
int main(){
 char a[30], b[30];
 printf("Enter the first string: ");
 gets(a);
 printf("Enter the second string: ");
 gets(b);
 concatenate(a,b);
 getch();
 return 0;
}
