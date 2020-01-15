char *trimspace(char *str)
{
char *str1,*str2;
str1=str;
str2=str;
while(*str1)
{
if (*str1!=' ')
{
*str2=*str1;
str1++;
str2++;
}
str1++;
}
*str2='\0'
return str2;
}
