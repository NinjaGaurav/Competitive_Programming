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
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,l,a,x,ans=0;
	cin>>n>>l>>a;
	ll start=0,fin=0;
	rep(i,0,n)
	{
	    cin>>x;fin=x;cin>>x;    //fin=task's start time
        ans+=(fin-start)/a;     //fin - start to find free time
        start=fin+x;    //start=task's start time + duration
	}
	ans+=(l-start)/a;       //fin - start for time left for Bacchus
	cout<<ans;
	return 0;
}
