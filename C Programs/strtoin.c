int strtoint(char k[])
{
int i=0,s=0;
while (k[i]!='\0')
{
s=s*10+k[i]-'0';
i++;
}
return s;
}
