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

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,i,j,k;
	cin>>n;
	ll a[n];
	rep(i,0,n)
	cin>>a[i];
	ll x=0;
	do{
        cin>>i>>j>>k;
        x=a[i-1]^a[j-1]^a[k-1];
        cout<<x<<endl;
	}while(x!=-1);
	return 0;
}
