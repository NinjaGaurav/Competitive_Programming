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
	ll t,r,c,k;
	cin>>t;
	while(t--)
    {   ll ans=0;
        cin>>r>>c>>k;
        ll chess[9][9]; //1 - 8
        for(int i=0;i<=8;i++)
        {
            for(int j=0;j<=8;j++)
            {
                chess[i][j]=0;
            }
        }
        chess[r][c]=1;
        ll x1=max(r-k,(ll)1),x2=min((ll)8,r+k),y1=max(c-k,(ll)1),y2=min((ll)8,c+k);
        for(ll x=x1;x<=x2;x++)
        {
            for(ll y=y1;y<=y2;y++)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
        cout<<flush;

    }
	return 0;
}
