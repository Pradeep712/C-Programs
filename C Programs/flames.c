#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
int i,j,n,c,s=0,p,t,y;
char a[25],b[25],m,q[25],w[25];
clrscr();
printf("Enter Ur Name");
scanf("%s",a);

printf("Enter Ur Partner's Name");
scanf("%s",b);
strcpy(q,a);
strcpy(w,b);
n=strlen(a);
c=strlen(b);
for(i=0;i<n;i++)
{
m=a[i];
for(j=0;j<c;j++)
{
if(m==b[j])
{
a[i]=-1;
b[j]=-1;
s=s+2;
break;
}
}
}
p=n+c;
puts(a);
puts(b);
t=p-s;
printf("The count value is %d",t);

if(t==2 || t==4 || t==7 ||t==9 )
printf("%s is ENEMY to %s ?,q,w);
else if (t==3 || t==5 || t==14)
printf("%s is FRIEND to %s ",q,w);
else if(t==6 || t==11 || t==15 )
printf("%s is going to MARRY %s ?+?",q,w);
else if(t==10)
printf("%s is in LOVE with %s ",q,w);
else if(t==8)
printf("%s has more AFFECTION on %s ",q,w);
else
printf("%s and %s are SISTERS/BROTHERS ",q,w);
getch();
}

