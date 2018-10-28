/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET		   //
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define repi(i, a, b) for(long long i = a; i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
ll N;
ll dp[105][105][105];
ll solve(ll arr[],ll n,ll a1,ll a2)
{   //if we draw a nice tree we see repeating calls :D
    ll x=0,y=0,z=0;
    if(n>N)
        return 0;
    if(dp[n][a1][a2]!=-1)
        return dp[n][a1][a2];

    if(a1==0 || arr[n]>arr[a1])
    x=1+solve(arr,n+1,n,a2);

    if(a2==0 || arr[n]<arr[a2])
    y=1+solve(arr,n+1,a1,n);

    z=solve(arr,n+1,a1,a2);

    return dp[n][a1][a2]=max(max(x,y),z);       // ans considering elements n to LAST
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>N;
        ll arr[1+N];
        rep(i,0,N)
            cin>>arr[1+i];
        cout<<solve(arr,1,0,0)<<endl;   //storing index instead of val to save storage space?
        //endl issue? -_-
    }
	return 0;
}
