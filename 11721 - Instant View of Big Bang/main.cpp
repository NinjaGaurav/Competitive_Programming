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
#define MP make_pair
#define PB push_back
typedef int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
void dfs(ll src,vi &vis,ll ans[],vector< vector<pii> > &graph)
{
    if(vis[src])
        return;
    vis[src]=1;
    rep(i,0,sz(graph[src]))
    {
        if(!vis[graph[src][i].second])
        {
            ans[graph[src][i].second]=1;
            dfs(graph[src][i].second,vis,ans,graph);

        }
    }
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    ll t;
    cin>>t;
    rep(T,0,t)
    {
        ll n,m;
        cin>>n>>m;
        ll ans[n]={0};
        vector< vector<pii> > graph(n);
        vi dist(n,0);// can start from any
        ll source,dest,cost;
        rep(i,0,m)
        {
            cin>>source>>dest>>cost;
            graph[dest].PB(MP(cost,source));
        }
        //bellmanford n*m
        rep(i,0,n-1)
        {
            rep(j,0,n)
            {
                rep(k,0,sz(graph[j]))
                {
                    if(dist[graph[j][k].second]> dist[j]+graph[j][k].first)
                        dist[graph[j][k].second]=dist[j]+graph[j][k].first;
                }
            }
        }
        // -ve cycle nodes
        rep(j,0,n)
            {
                rep(k,0,sz(graph[j]))
                {
                    if(dist[graph[j][k].second]> dist[j]+graph[j][k].first)
                        ans[j]=ans[graph[j][k].second]=1;
                }
            }
        //repeated dfs
        vi vis(n,0);
        rep(i,0,n)
            if(ans[i]){
                dfs(i,vis,ans,graph);
            }

        // ans
        ll impossible_flag=1;
        cout<<"Case "<<T+1<<":";
        rep(i,0,n)
            if(ans[i])
            { cout<<" "<<i; impossible_flag=0; }
        if(impossible_flag)
            cout<<" impossible";
        cout<<endl ;

    }
	return 0;
}
