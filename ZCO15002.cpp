/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET, Bijwasan //
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define endl '\n'
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    ll n,k,ans=0;
    cin>>n>>k;
    vector<ll> a(n);
    rep(i,0,n)
    cin>>a[i];
    sort(a.begin(),a.end());
    rep(i,0,n)
    {
        if((lower_bound(a.begin(),a.end(),a[i]+k)-a.begin())<=n-1)
        ans+=n-(lower_bound(a.begin(),a.end(),a[i]+k)-a.begin());
    }
    cout<<ans;

	return 0;
}
