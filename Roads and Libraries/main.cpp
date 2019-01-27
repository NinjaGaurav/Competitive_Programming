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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,l,r,x,y;
        cin>>n>>m>>l>>r;
        vi graph[n+1];
        vi vis(n+1,0);
        rep(i,0,m)
        {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);

        }
        queue<ll> Q;
        ll ans=0;
        rep(node,1,n+1)
        {
            if(!vis[node])
            {
                Q.push(node);
                vis[node]=1;
                ll ctr=1;
                while(Q.size()>0)
                {
                    x=Q.front();
                    Q.pop();
                    rep(i,0,graph[x].size())
                    {
                        if(!vis[graph[x][i]])
                        {   ++ctr;
                            vis[graph[x][i]]=1;
                            Q.push( graph[x][i] );
                        }
                    }
                }
                ans+=min(ctr*l,l+(ctr-1)*r);
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
