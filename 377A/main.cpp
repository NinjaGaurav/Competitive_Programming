///////////////////////////////////
//      Author:  Gaurav Bholla   //
//      Institution: ASET        //
///////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repi(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector< vector<ll> > matrix;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,m,k; char c; ll src=-1, s=0;
	cin>>n>>m>>k;
	matrix arr(n,vi(m));
	rep(i,0,n)
        rep(j,0,m)
            {
               cin>>c;
               arr[i][j]=(c=='#')?  0  : 1  ;
               if(src==-1 && arr[i][j])
                src=i*m + j;
               if(arr[i][j])
                ++s;
            }
    vi graph[n*m];
    vi vis(n*m);
    rep(i,0,n)
    rep(j,0,m)
    {
        if(!arr[i][j])
            continue;
        if(i+1<n && arr[i+1][j])
        {
            graph[i*m+j].PB((i+1)*m+j);
            graph[(i+1)*m+j].PB((i)*m+j);
        }
        if(j+1<m && arr[i][j+1])
        {
            graph[i*m+j].PB((i)*m+j+1);
            graph[(i)*m+j+1].PB((i)*m+j);
        }
    }
    ll rem= s - k;
    queue<ll> Q;
    Q.push(src);
//    cout<<"O :"<<src<<endl;
    while(rem)
    {
        ll tmp=Q.front();
        Q.pop();
        if(vis[tmp])
            continue;
        vis[tmp]=1;
        rem--;
        trav(a, graph[tmp])
            if(!vis[a]){
//                cout<<a<<endl;
                Q.push(a);
            }
    }

    while(Q.size())
    {
        ll tmp=Q.front();
        Q.pop();
        if(vis[tmp])
            continue;
        vis[tmp]=1;
        trav(a, graph[tmp])
            if(!vis[a]){
//                cout<<a<<endl;
                Q.push(a);
            }
        ll x=tmp/m;
        ll y=tmp%m;
        arr[x][y]=-1;

    }
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(arr[i][j]==-1)
                cout<<"X";
            else if(arr[i][j]==1)
                cout<<".";
            else
                cout<<"#";
        }
        cout<<endl;
    }
	return 0;
}
