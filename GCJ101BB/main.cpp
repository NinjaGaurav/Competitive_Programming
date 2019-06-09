/////////////////////////////////////
//	Author: Gaurav Bholla      //
//	Institution: ASET	   //
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repi(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define endl '\n'
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	rep(tt,1,t+1)
	{
	    ll n,k,b,t,seen=0,ans=0;
	    cin>>n>>k>>b>>t;
	    vi X(n),V(n);
        trav(a,X)
            cin>>a;
        trav(a,V)
            cin>>a;

        for(ll i=n-1;i>=0;i--)
        {
            if(b<=X[i]+V[i]*t)
            {
                ans+=seen;
                --k;
            }
            else
                ++seen;
            if(k==0)
                break;
        }
        cout<<"Case #"<<tt<<": ";
        (k==0)?cout<<ans:cout<<"IMPOSSIBLE";
        cout<<endl;

	}
	return 0;
}
