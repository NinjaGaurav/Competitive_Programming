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
	ll n,k,p,x,cnt,ans=1;
	cin>>n>>k;
	vi graph[n];
	int visited[n]={0};

	rep(i,0,n)
	{
	    cin>>p;
	    rep(j,0,p)
	    {
	        cin>>x;
	        graph[i].push_back(x);
	    }
	}
	queue<ll> Q;
	Q.push(0);
	visited[0]=1;
	while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        unordered_map<ll,ll> cache;
        rep(i,0,graph[x].size())
        {
            cache[graph[x][i]]=1;
        }
        rep(i,0,n)
        {
            if(!visited[i])
            {   cnt=0;
                rep(j,0,graph[i].size())
                {
                    if(cache[graph[i][j]])
                        cnt++;
                }
                if(cnt>=k)
                {
                    Q.push(i);
                    visited[i]=1;
                    ans++;
                }
            }
        }

    }
    cout<<ans;
	return 0;
}
