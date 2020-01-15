 #include<iostream>
#include<stdio.h>                             //used for gets()
#include<string.h>                           //used for strcmp()

using namespace std;

class String
{
        char str[20];

        public:
        void getdata()                            //function to read the string
        {
                gets(str);
        }

        //operator function to overload comparison operator and compare two strings
        int operator ==(String s)
        {
                if(!strcmp(str,s.str))
                return 1;

                return 0;
        }
};

main()
{
        String s1,s2;
        cout<<"Enter first string:";
        s1.getdata();
        cout<<"Enter second string:";
        s2.getdata();

        if(s1==s2)                                    //here the operator function will be called
        {
                cout<<"\nStrigs are Equal\n";
        }
        else
        {
                cout<<"\nStrings are Not Equal\n";
        }

        return 0;
}

