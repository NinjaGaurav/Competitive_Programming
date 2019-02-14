/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET		   //
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repi(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define endl '\n'
typedef int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    ll n,x,y,k[100001],ans[100001],visited[100001],fans,maxdis;
    cin>>n;
    rep(i,1,n+1)
    cin>>k[i];
    vi graph[n+1];
    rep(i,0,n-1)
    {
        cin>>x>>y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    rep(z,1,n+1)
    {
            unordered_map<ll, ll> mymap;
            ++mymap[0];
            rep(i,1,1+n)
                visited[i]=0;
            maxdis=0;
            queue<ll> Q;
            Q.push(z);
            visited[z]=1;
            while(!Q.empty())
            {
                ll X=Q.front();
                Q.pop();
                for(ll i=0;i<graph[X].size();++i)
                {
                    if(!visited[graph[X][i]])
                    {
                        visited[graph[X][i]]=visited[X]+1;
                        ++mymap[visited[X]];
                        maxdis=max(maxdis,visited[X]);
                        Q.push( graph[X][i] );
                    }
                }
            }
            fans=0;
            if(mymap[maxdis]>=k[z])
                {
                    ans[z]=maxdis-1;
                    continue;
                }

            for(ll i=maxdis-1;i>=0;i--)
            {
                mymap[i]+=mymap[i+1];
                if(mymap[i]>=k[z])
                {
                    fans=i-1;
                    break;
                }
            }
            ans[z]=fans;

    }
    rep(z,1,n+1)
        cout<<ans[z]<<" ";
	return 0;
}
