/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET, Bijwasan //
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
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n;
	cin>>n;
	ll arr[n],dp[n];
	rep(i,0,n)
        cin>>arr[i];
	rep(i,0,n)
    {
        dp[i]=1;
        repi(j,i-1,0)
        {
           if(arr[i]*arr[j]<0 && abs(arr[i])>abs(arr[j]))
           dp[i]=max(dp[i],dp[j]+1);
        }
    }
    cout<<*max_element(dp,dp+n);
	return 0;
}
