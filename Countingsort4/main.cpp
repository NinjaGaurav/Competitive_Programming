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

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,x;
	string s;
	cin>>n;

	vector< vector<string> > arr(100);
	rep(i,0,n/2)
	{
	    cin>>x>>s;
	    arr[x].push_back("-");
	}
	rep(i,n/2,n)
	{
	    cin>>x>>s;
	    arr[x].push_back(s);
	}
	rep(i,0,100)
	{
	    rep(j,0,arr[i].size())
            cout<<arr[i][j]<<" ";
	}
	return 0;
}
