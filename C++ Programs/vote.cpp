/* for each integer from 0 to M the function would calculate how many times this number appears in the N-element array
algorithm complexity O(1) */
#include <iostream>
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
    cout << n * (m + 1) << endl;
    return (0);
}