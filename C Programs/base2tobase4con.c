//base2tobase4conv
#include<stdio.h>
#include<string.h>
main()
{
	int i,l,k;
	char s[20];
	printf("Enter a base 2 number : ");
	gets(s);
	l=strlen(s);
	k=i=(l%2==0)?0:1;
	while(i<l)
	{
		if(s[i]=='0' && s[i+1]=='0')
		s[k++]='0';
		else if(s[i]=='0' && s[i+1]=='1')
		s[k++]='1';
		else if(s[i]=='1'&& s[i+1]=='0')
		s[k++]='2';
		else
		s[k++]='3';
		i+=2;
	}
 	s[k]=NULL;
	printf("The base 4 string is : ");
	puts(s);
}