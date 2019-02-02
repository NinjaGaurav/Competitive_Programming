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
class mycomp
{
public:
    int operator() (const pair<ll,ll>& p1, const pair<ll,ll>& p2)
    {
        return p1.second > p2.second; //min heap, second is cost
    }
};
ll dij(ll s,ll d,vector< pair<ll,ll> >* graph,ll n)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, mycomp> heap;
    vi vis(n+1,0);
    //parent not needed?
    vi dist(n+1,numeric_limits<ll>::max());
    dist[s]=0;
    heap.push(make_pair(s,dist[s]));
    while(heap.size()>0)
    {
        if(vis[d])
            break;      //0.35secs with this; 0.65secs without it
        pii tmp=heap.top();
        heap.pop();
        if(vis[tmp.first])
            continue;
        vis[tmp.first]=1;
        rep(i,0,graph[tmp.first].size())
        {
            if(!vis[graph[tmp.first][i].first])
                {
                    ll newdist=dist[tmp.first]+ graph[tmp.first][i].second;
                    if(dist[graph[tmp.first][i].first]==numeric_limits<ll>::max() || newdist<dist[graph[tmp.first][i].first])
                        {
                            dist[graph[tmp.first][i].first]=newdist;
                            heap.push(make_pair(graph[tmp.first][i].first,dist[graph[tmp.first][i].first]));
                        }
                }
        }
    }
    return dist[d];
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,x,d,c;
        cin>>n;
        string s;
        vector< pair<ll,ll> > graph[n+1];
        unordered_map<string,ll> M;
        rep(i,1,n+1)
        {
            cin>>s;
            M[s]=i;
            cin>>x;
            rep(j,0,x)
            {
                cin>>d>>c;
                graph[i].push_back(make_pair(d,c));
            }
        }
        ll query;
        cin>>query;
        rep(i,0,query)
        {
            string source,dest;
            cin>>source>>dest;
            cout<<dij(M[source],M[dest],graph,n)<<endl;
        }
    }
	return 0;
}
