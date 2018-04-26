// C++ program to count number of 2 x 2
// squares in a right isosceles triangle
#include<bits/stdc++.h>
using namespace std;
long long numberOfSquares(long long base)
{   
    if(base%2==1)
        base--;
        
    return base*base/8-base/4;
}
int main()
{
    long q,x;
    cin>>q;
    while(q--)
    {   
        cin>>x; 
        cout << numberOfSquares(x)<<endl;
    }
    return 0;
}
