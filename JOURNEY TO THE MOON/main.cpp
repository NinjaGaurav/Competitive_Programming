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
        ll n,m,x,y;
        cin>>n>>m;
        vi graph[n];
        vi vis(n,0),pnc,pnc_sum;
        rep(i,0,m)
        {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);

        }
        queue<ll> Q;
        ll ans=0;
        rep(node,0,n)
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
                pnc.push_back(ctr);
            }
        }

        pnc_sum.push_back(pnc[0]);
        rep(i,1,sz(pnc))                                // Done to convert O(n^2) to O(n)
            pnc_sum.push_back(pnc_sum[i-1]+pnc[i]);     // sum from 0 to ith item

        rep(i,0,sz(pnc)-1)                                  // Done to convert O(n^2) to O(n)
        {
            ans+=pnc[i]*(pnc_sum[sz(pnc)-1]-pnc_sum[i]);    // A*x+A*y+A*z=A*(x+y+z)
        }
        cout<<ans<<endl;

	return 0;
}
