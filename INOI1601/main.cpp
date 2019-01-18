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
vi graph[100000+1];
ll A[100000+1],P[100000+1],visited[100000+1];

void widow_maker(ll s, ll tmpmax)
{
    for(ll i=0;i<graph[s].size();i++)
    {
        if(visited[graph[s][i]]!=1)
        {   visited[graph[s][i]] = 1;
            ans=max(ans,tmpmax-A[graph[s][i]]);
            widow_maker(graph[s][i], max(tmpmax,A[graph[s][i]]) );      //ans finder >_>
        }
    }
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,s;
	cin>>n;
	rep(i,1,n+1)
        cin>>A[i];
	rep(i,1,n+1)
        cin>>P[i];

    rep(i,1,n+1)
    {
        if(P[i]==-1)
        {
            s=i;
        }
        else
        {
            graph[P[i]].push_back(i);
        }
    }
    widow_maker(s,A[s]);
    cout<<ans;
	return 0;
}
