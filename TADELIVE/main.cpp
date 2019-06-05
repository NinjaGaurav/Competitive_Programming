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
struct GTX{
    ll andy,bob,delta;
};
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,x,y,res=0;
	cin>>n>>x>>y;
	GTX ans[n];
	rep(i,0,n)
        cin>>ans[i].andy;
    rep(i,0,n)
    {
        cin>>ans[i].bob;
        ans[i].delta=ans[i].andy-ans[i].bob;
    }
    sort(ans,ans+n,[](auto& X, auto& Y){ return abs(X.delta)>abs(Y.delta); });
    rep(i,0,n)
    {
        if(ans[i].delta>=0)
        {
            if(x){
                res+=ans[i].andy;
                x--;
            }
            else{
                res+=ans[i].bob;
                y--;
            }
        }
        else
        {
            if(y){
                res+=ans[i].bob;
                y--;
            }
            else{
                res+=ans[i].andy;
                x--;
            }
        }
    }
    cout<<res;
	return 0;
}
