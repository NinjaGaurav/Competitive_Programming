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
	ll t;cin>>t;
	while(t--){
	char x;
	ll n,m,ans=1;
	cin>>n>>m;
	ll popo[n][m],topo[n][m];
	rep(i,0,n)
        rep(j,0,m)
            topo[i][j]=0;
	rep(i,0,n)
        rep(j,0,m)
            popo[i][j]=1;
	rep(i,0,n)
        rep(j,0,m)
            {
                cin>>x;
                if(x=='#')
                    popo[i][j]=0;
            }
    rep(i,0,n-1)
        rep(j,0,m-1)
        {
            if(popo[i][j]+popo[i+1][j]+popo[i][j+1]+popo[i+1][j+1]==4)
            {
                topo[i][j]=topo[i+1][j]=topo[i][j+1]=topo[i+1][j+1]=1;
            }
        }
    rep(i,0,n)
        rep(j,0,m)
        {
            if(popo[i][j]!=topo[i][j])
            {
                ans=0;
            }
        }
    (ans==1)?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
}
