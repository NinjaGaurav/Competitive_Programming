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
	ll n;
	cin>>n;
	ll cost[n][n];
	rep(i,0,n)
        rep(j,0,n)
            cin>>cost[i][j];
    ll k;
    cin>>k;
    while(k--)
    {
        ll s,d,c,ans=0;
        cin>>s>>d>>c;
        cost[--s][--d]=cost[d][s]=min(cost[s][d],c);
        rep(i,0,n)
            rep(j,0,n)
            {
                cost[i][j]=cost[j][i]=min(cost[i][j],cost[i][s]+c+cost[d][j]);
            }
        rep(i,0,n)
            rep(j,i+1,n)
                ans+=cost[i][j];
        cout<<ans<<endl;
    }
	return 0;
}
