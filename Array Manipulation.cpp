/////////////////////////////////////
//    Author:            Gaurav Bholla  //
//    Institution:     ASET, Bijwasan //
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {

    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n,m,a,b,k,x=0,ans=-10000;
    cin>>n>>m;
    vector<ll> arr(n+5,0);
    rep(i,0,m)
    {
        cin>>a>>b>>k;
        arr[a]+=k;
        arr[b+1]+= (-k);
    }
    rep(i,1,n+1)
    {
        x+=arr[i];        
        ans=max(ans,x);
    }
    cout<<ans;
    return 0;

}
