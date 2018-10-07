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
//could be done faster but who cares :)
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n;
	cin>>n;
	ll N=n;
	ll prev=1,cur=2;
	while(N>1)
	{
	    rep(j,prev+1,n+1)
	    if(n/j>=n/cur && j%prev==0)
            cur=j;
        N=N-n/cur;   //total no deleted= current arr len - nos. with cur as gcd
        rep(j,0,N)
        cout<<prev<<" ";
        N=n/cur;    //total no left now;since some deleted to reach this len(same gcd)
        prev=cur;
        cur=n;
    }
    cout<<prev;
	return 0;
}
