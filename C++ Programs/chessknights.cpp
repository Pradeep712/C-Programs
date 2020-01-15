/*The first line of the input is an integer containing the number of total tests, followed by the locations, one each line. The location is represented by two characters, the first is a letter from ‘a’ to ‘h’ and the second is a digit from 1 to 8.

You are required to output the number of positions being attached. You have to convert the first coordinate to integer and check if any of the 8 attacking positions are still on board (in range). Bruteforce implementation is a piece of cake.*/

#include <iostream>
 
using namespace std;
 
int pos(char x)
{
    if ((x >= '0') && (x <= '9'))   
    {       
        return ((int)(x - '0'));    
    }   
    return ((int)(x - 'a' + 1)); 
} 
 
int test(int x, int y) 
{   
    if ((x > 0) && (x <= 8) && (y > 0) && (y <= 8))     
    {       
        return (1);     
    }   
    return (0); 
} 
 
int loc(char x, char y) 
{   
    int xx = pos(x);    
    int yy = pos(y);    
    return (        
        test(xx - 2, yy + 1) +      
        test(xx + 2, yy + 1) +      
        test(xx - 2, yy - 1) +      
        test(xx + 2, yy - 1) +      
        test(xx - 1, yy + 2) +      
        test(xx + 1, yy + 2) +      
        test(xx - 1, yy - 2) +      
        test(xx + 1, yy - 2)    
    ); 
} 
 
int main() {    
    int n;  cin >> n;
    char x, y;
    for (int i = 0; i < n; i ++)    
    {       
        cin >> x >> y;
        cout << loc(x, y) << endl;
    }
    return (0);
}

