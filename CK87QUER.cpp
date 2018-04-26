#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main()
{   
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t,y,c;
    cin>>t;
    while(t--)
    {   c=0;
        cin>>y;
        for(ll b=1;b<=700 && (y-b)>=1;b++)
        {
            c+=floor(sqrt(y-b));
               
        }
        cout<<c<<'\n';
        
    }
    
    return 0;
}
