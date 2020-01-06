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
    ll n,q;
    cin>>n>>q;
    vector<string> pop = {"ddd","ggg"};
    vi arr(n);
    trav(a,arr)
        cin>>a;
    sort(all(arr),greater<ll>());
    vi freq(200005); ll x,y,fix=0,tmp;
    rep(i,0,q)
    {
        cin>>x>>y;
        freq[x]++;
        freq[y+1]--;
    }
    trav(a,freq)
    {
        tmp=a;
        a+=fix;
        fix+=tmp;
    }
    tmp=0;
    sort(all(freq),greater<ll>());
    rep(i,0,n)
    {
        tmp+=arr[i]*freq[i];
    }
    cout<<tmp;
	return 0;
}
