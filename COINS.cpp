#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int 
ll memo[50000];
ll ans(ll n)
{
    if(n<12)
    {   memo[n]=n;
        return memo[n];
    }
    else if(n<50000 && memo[n]!=0)
    {
        return memo[n];
    }
    else if(n<50000 && memo[n]==0)
    {
        memo[n]=max(n,ans(n/2)+ans(n/3)+ans(n/4));
        return memo[n];
    }
    else
    return max(n,ans(n/2)+ans(n/3)+ans(n/4));
    
    
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    ll n;
    while(cin>>n)
    {
        cout<<ans(n)<<'\n';
    }
    
 
 
 
	return 0;
}
