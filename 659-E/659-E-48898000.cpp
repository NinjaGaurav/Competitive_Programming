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
ll ans=0;
vi graph[100001];
ll vis[100001], parent[100001];
bool flag=false;
void dfs(ll x)
{
    vis[x]=1;
    rep(i,0,graph[x].size())
    {
        if(!flag && vis[graph[x][i]]!=0 && parent[x]!=graph[x][i])
            flag=true;  // cycle, 0 separate cities
        if(!vis[graph[x][i]])
        {
             parent[graph[x][i]]=x;
             dfs(graph[x][i]);
        }

    }
}
void solve(ll n)
{
    rep(i,1,n+1)
    {
        if(!vis[i])
        {
            ans++;
            parent[i]=-1;  //source
            dfs(i);
            if(flag)
            {
                ans--;
                flag=false;
            }
        }
    }
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,m,x,y;
	cin>>n>>m;
	rep(i,0,m)
	{
	    cin>>x>>y;
	    graph[x].push_back(y);
	    graph[y].push_back(x);
	}
	solve(n);
	cout<<ans;
	return 0;
}