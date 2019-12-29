///////////////////////////////////
//      Author:  Gaurav Bholla   //
//      Institution: ASET        //
///////////////////////////////////
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
#define FI first
#define SE second
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector< vector<ll> > matrix;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,m,ans=0;
        cin>>a>>m;
        vi factors;
        vi alln;
        for(ll i=1;i<=sqrt(m);i++)
        {
            if(m%i==0)
            {
                factors.PB(i);
                if(i!=m/i)
                    factors.PB(m/i);
            }
        }
        trav(k, factors)
        {
            if((k-1)%a==0 && k!=1){
                ++ans;
                alln.PB( m/( (k-1) + 1)*((k-1)/a));
            }
        }
        cout<<ans<<endl;
        sort(all(alln));
        trav(N, alln)
            cout<<N<<" ";
        cout<<endl;
    }
	return 0;
}
