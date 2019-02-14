/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET		   //
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(long i = a; i < (b); ++i)
#define repi(i, a, b) for(long i = a; i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define endl '\n'
typedef long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
ll arr[5001],vis[50001];vector<pii> graph[50001];ll dist[50001];
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    ll n,bob,k;
    cin>>n;
    rep(i,0,n)
        cin>>arr[i];
    rep(i,0,50001)
        dist[i]=numeric_limits<ll>::max();

    priority_queue< pii ,vector<pii>, greater<pii> > heap;
    dist[0]=0;
    heap.push(make_pair(0,0));
    while(heap.size()>0)// pi has dist then node
    {
        pii tmp=heap.top();
        heap.pop();
        if(vis[tmp.second])
            continue;
        vis[tmp.second]=1;
        rep(i,0,n)
        {   bob=(tmp.first+arr[i])%arr[0];
            if(!vis[bob])
                {
                    if(dist[bob]==numeric_limits<ll>::max() || dist[tmp.second]+ arr[i]<dist[bob])
                        {
                            dist[bob]=dist[tmp.second]+ arr[i];
                            heap.push( make_pair( dist[bob], bob ) );
                        }
                }
        }
    }
    cin>>k;
    rep(j,0,k)
        {
            cin>>bob;
            (dist[bob%arr[0]]<=bob)?cout<<"TAK\n":cout<<"NIE\n";
        }
	return 0;
}
