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
	ll t,n;
    cin>>n>>t;
    matrix arr(n,vi(t+1));
    vi winner(n);
    rep(i,0,n)
    {
        rep(j,0,t+1)
            cin>>arr[i][j];
    }
    rep(i,0,n)
    {
        rep(j,1,t)
            arr[i][j]+=arr[i][j-1];
    }
    rep(i,0,n)
    {
        rep(j,0,t)
            arr[i][j]*=arr[i][t];
    }
    ll t2=t-1;
    for(ll ts=2;ts<=t2;ts+=2)
    {
        ll pw=-1,pwd=-1;
        rep(i,0,n)
        {
            if(arr[i][ts-1]>=pwd)
            {
                pwd=arr[i][ts-1];
                pw=i;
            }
        }
        winner[pw]++;
    }
    ll victor=0,victorwins=0;
    rep(i,0,sz(winner))
    {
        if(winner[i]>victorwins)
        {
            victor=i+1;
            victorwins=winner[i];
        }
    }
    cout<<victor<<endl;
	return 0;
}
