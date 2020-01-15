#include<stdio.h>
int main()
{
char s[200];
int len;
printf("Enter a string:");
gets(s);
len=printf("%s",s);
printf("\nLength=%d",len);

return 0;
}
