#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ll n,r,c;
    cin>>n>>r>>c;
    ll arr[n],memo[n+1]={0};
	for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        if(i<=4)
            memo[i]=min(memo[i-1]+arr[i-1]*r,c);
        else
            memo[i]=min(memo[i-1]+arr[i-1]*r, memo[i-4]+c);
    }
    cout<<memo[n];
	return 0;
}
