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
#define MOD 1000000007
ll n,k,d;
ll memo[169][2];
ll dfs(ll wt,ll e)
{
    if(wt>=0 && memo[wt][e]!=-1)
        return memo[wt][e];
    if(wt==0 && e)
        return 1;
    else if(wt<=0)
        return 0;
    ll ans=0;
    rep(i,1,k+1)
    {
        ans=(ans)%MOD+dfs(wt-i,(i>=d)?1:e)%MOD;
        ans%=MOD;
    }
    return memo[wt][e]=ans%MOD;
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    trav(x, memo)
        trav(y, x)
            y=-1;
	cin>>n>>k>>d;
	cout<<dfs(n,0);
	return 0;
}
