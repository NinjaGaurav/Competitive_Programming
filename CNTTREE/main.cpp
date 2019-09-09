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
ll n,k;
matrix graph(69);
ll memo[69][69];
ll tmp[69];
void solve(ll root, ll parent)
{

    memo[root][0]=1;
    trav(child,graph[root])
    {
        if(child==parent)
            continue;
        solve(child,root);
        memset(tmp,0LL,sizeof(tmp));
        rep(rd,0,k) //k-1 max val, add any other node so k-1+1=k
        {
            rep(cd,0,k-rd)
            {
                tmp[max(rd,cd+1)]+= memo[root][rd]*memo[child][cd];
            }
        }
        rep(i,0,69)
            memo[root][i]+=tmp[i];
    }
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(memo,0,sizeof(memo));
        rep(i,0,69)
            graph[i].clear();

        rep(i,0,n-1)
        {
            ll x,y;
            cin>>x>>y;
            graph[x].PB(y);
            graph[y].PB(x);
        }
        solve(0,-1);
        ll ans=0;
        rep(i,0,n)
            rep(d,0,k+1)
                ans+=memo[i][d];
        cout<<ans<<endl;
    }
	return 0;
}
