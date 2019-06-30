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

void Floyd_Warshall(std::vector<std::vector<ll>> &cost) {
    ll n = cost.size();

    for (ll i = 0; i < n; i++) {
        cost[i][i] = 0;
    }

    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                cost[i][j] = std::min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

struct graph
{
    ll u,v,wt;
};
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	rep(tc,1,t+1)
	{   graph helper;
	    ll n,m,x,y,wt,flag=1;
	    cin>>n>>m;
	    vector< vector<ll> > cost(n, vector<ll>(n,10000000000));
	    vector<graph> arr(m);
	    rep(i,0,m)
	    {
	        cin>>x>>y>>wt;
	        cost[x-1][y-1]=cost[y-1][x-1]=wt;   // 0 index conversion
	        helper.u=x-1;
	        helper.v=y-1;
	        helper.wt=wt;
	        arr[i]=helper;
	    }
	    Floyd_Warshall(cost);
	    cout<<"Case #"<<tc<<": ";
	    rep(i,0,m)
	    {
	        if(arr[i].wt!=cost[arr[i].u][arr[i].v])
            {
                flag=0;
                break;
            }
	    }
	    if(!flag)
            cout<<"Impossible\n";
        else
        {
            cout<<m<<endl;
            rep(i,0,m)
            {
                cout<<arr[i].u+1<<" "<<arr[i].v+1<<" "<<arr[i].wt<<endl;    //convert to 1 index
            }
        }
	}
	return 0;
}
