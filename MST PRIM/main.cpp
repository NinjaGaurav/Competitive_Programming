///////////////////////////////////
//      Author:  Gaurav Bholla   //
//      Institution: ASET        //
///////////////////////////////////
// IITWPC4I - Petya and the Road Repairs

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
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector< vector<ll> > matrix;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vi dhudhvala(n);
        trav(a,dhudhvala)
            cin>>a;
        vector< vector<pii> > arr(n+1);
        ll x,y,dis;
        rep(i,0,m)
        {
            cin>>x>>y>>dis;
            arr[x].PB({dis,y});
            arr[y].PB({dis,x});
        }

        ll ans=0;
        vi visited(n+1,0);
        priority_queue<pii, vector<pii>, greater<pii> > heap;  // pair: (wt, v)
        rep(i,0,n)
            if(dhudhvala[i])
                heap.push({0,i+1});
        pii tmp;
        while(heap.size()>0)
        {
            tmp = heap.top();
            heap.pop();
            if(visited[tmp.second])
                continue;
            visited[tmp.second]=1;
            ans+=tmp.first;
            trav(item, arr[tmp.second])
            {
                if(visited[item.second]==0)
                {
                    heap.push({item.first,item.second});
                }
            }
        }

        (accumulate(all(visited),0)==n)?cout<<ans<<endl : cout<<"impossible\n";
    }
	return 0;
}
