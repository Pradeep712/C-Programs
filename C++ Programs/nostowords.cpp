#include<iostream.h>
#include<conio.h>

void once(int a)
{
	switch(a)
	{
		case 1: cout<<"One";
			break;
		case 2: cout<<"Two";
			break;
		case 3: cout<<"Three";
			break;
		case 4:	cout<<"Four";
			break;
		case 5: cout<<"Five";
			break;
		case 6: cout<<"Six";
			break;
		case 7: cout<<"Seven";
			break;
		case 8: cout<<"Eight";
			break;
		case 9: cout<<"Nine";
			break;
	}
}

int tens(int a,int b)
{
	int flag=0;
	switch(a)
	{
		case 1:
			flag=1;
			switch(b)
			{
				case 0: cout<<"Ten";
					break;
				case 1: cout<<"Eleven";
					break;
				case 2: cout<<"Twelve";
					break;
				case 3: cout<<"Thirteen";
					break;
				case 4: cout<<"Fourteen";
					break;
				case 5: cout<<"Fifteen";
					break;
				case 6: cout<<"Sixteen";
					break;
				case 7: cout<<"Seventeen";
					break;
				case 8: cout<<"Eighteen";
					break;
				case 9: cout<<"Nineteen";
					break;
			}
			break;
		case 2: cout<<"Twenty";
			break;
		case 3: cout<<"Thirty";
			break;
		case 4: cout<<"Fourty";
			break;
		case 5: cout<<"Fifty";
			break;
		case 6: cout<<"Sixty";
			break;
		case 7: cout<<"Seventy";
			break;
		case 8: cout<<"Eighty";
			break;
		case 9: cout<<"Ninety";
			break;
	}
	return(flag);
}

void hundred(int a)
{
	switch(a)
	{
		case 1: cout<<"One Hundred";
			break;
		case 2: cout<<"Two Hundred";
			break;
		case 3: cout<<"Three Hundred";
			break;	
		case 4: cout<<"Four Hundred";
			break;
		case 5: cout<<"Five Hundred";
			break;
		case 6: cout<<"Six Hundred";
			break;
		case 7: cout<<"Seven Hundred";
			break;
		case 8: cout<<"Eight Hundred";
			break;
		case 9: cout<<"Nine Hundred";
			break;
	}
}

void main()
{
	clrscr();
	int n,a[3],i=0,flag=0;
	cout<<"Enter any number(max 3 digits):";
	cin>>n;

	while(n!=0)
	{
		a[i++]=n%10;
		n=n/10;
	}

	for(i=i-1;i>=0;--i)
	{
		if(i==0&&flag==0)
			once(a[0]);
		if(i==1)
			flag=tens(a[1],a[0]);
		if(i==2)
			hundred(a[2]);
		cout<<" ";
	}
	getch();
}