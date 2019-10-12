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
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector< vector<ll> > matrix;
void solve(matrix& M, ll sx, ll sy, ll ex, ll ey, ll r)
{
    vi tmp;
    rep(i,sy,ey)
        tmp.PB(M[sx][i]);
    rep(i,sx,ex)
        tmp.PB(M[i][ey]);
    repi(i,ey,sy+1)
        tmp.PB(M[ex][i]);
    repi(i,ex,sx+1)
        tmp.PB(M[i][sy]);

    r%=tmp.size();
    vi rtmp(tmp.size());
    rep(i,0,tmp.size())
        rtmp[i]=tmp[(i+r)%(tmp.size())];
    r=0;
    rep(i,sy,ey)
        M[sx][i]=rtmp[r++];
    rep(i,sx,ex)
        M[i][ey]=rtmp[r++];
    repi(i,ey,sy+1)
        M[ex][i]=rtmp[r++];
    repi(i,ex,sx+1)
        M[i][sy]=rtmp[r++];
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll m,n,r;
	cin>>m>>n>>r;
	matrix M(m,vi(n));
	rep(i,0,m)
        rep(j,0,n)
            cin>>M[i][j];
    ll sx=0,sy=0,ex=m-1,ey=n-1;
    while(sx<ex && sy<ey)
    {
        solve(M,sx,sy,ex,ey,r);
        sx++;sy++;ex--;ey--;
    }
    rep(i,0,m)
    {
        rep(j,0,n)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }

	return 0;
}
