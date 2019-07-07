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
ll t,n,s,u,v,chk;
ll solve(ll src, vi* graph,vi& vis,vi& cap)
{
    vis[src]=1;
    ll ans=0,tc=0;
    trav(node,graph[src])
    {
        if(!vis[node])
        {   ++tc;
            ans=max(ans,solve(node,graph,vis,cap));
        }
    }
    ans=ans*tc + cap[src];
    if(ans>10e18 || ans<0)
    {
        chk=1;
        return 0;
    }
    return ans;
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
    chk=0;
	cin>>n>>s;
	--s;
	vi cap(n);
	trav(a,cap)
        cin>>a;
    vi graph[n];
    vi vis(n,0);
    rep(i,0,n-1)
    {
        cin>>u>>v;
        --u;--v;
        graph[u].PB(v);
        graph[v].PB(u);
    }
    ll ans=solve(s,graph,vis,cap);
    if(!chk && (count(all(vis),1)==n))
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
	}
	return 0;
}
