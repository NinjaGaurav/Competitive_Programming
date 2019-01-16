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
	ll n,q,f,t,ans;
	cin>>n;
	ll x[n],y[n];
	rep(i,0,n)
	cin>>x[i]>>y[i];
	cin>>q;
	while(q--)
    {   ans=0;
        cin>>f>>t;
        rep(i,f-1,t)
            rep(j,i+1,t)
                ans=max(ans,(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        cout<<ans<<endl;
    }
	return 0;
}
