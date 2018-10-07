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
	char x;
	int n,m,ans=1;
	cin>>n>>m;
	int popo[n][m],topo[n][m];
	memset(topo,0,sizeof(topo));
	memset(popo,0,sizeof(popo));
	rep(i,0,n)
        rep(j,0,m)
            {
                cin>>x;
                if(x=='#')
                    popo[i][j]=1;
            }
    rep(i,0,n-2)
        rep(j,0,m-2)
        {
            if(popo[i][j]+popo[i+1][j]+popo[i+2][j]+popo[i][j+1]+popo[i][j+2]+popo[i+1][j+2]+popo[i+2][j+1]+popo[i+2][j+2]==8)
            {
                topo[i][j]=topo[i+1][j]=topo[i+2][j]=topo[i][j+1]=topo[i][j+2]=topo[i+1][j+2]=topo[i+2][j+1]=topo[i+2][j+2]=1;
            }
        }
    rep(i,0,n)
        rep(j,0,m)
        {
            if(popo[i][j]!=topo[i][j])
            {
                cout<<"NO";
                return 0;
            }
        }
    cout<<"YES";
	return 0;
}
