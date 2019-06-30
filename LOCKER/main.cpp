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
vi arr(1000000);
ll paw(ll a, ll x)
{
    if(x==0)
        return 1;
    ll tmp = paw(a,x/2);
    return (x&1)? (((a*tmp)%1000000007)*tmp)%1000000007 : tmp*tmp%1000000007 ;
}
ll ans(ll x)
{
    ll ans=1;
    while(x>=2)
    {
        if(x%3==0)
        {
            return ((ans%1000000007)*paw(3,x/3))%1000000007;;
        }
        else
        {
            ans*=2;
            x-=2;
        }
    }
    return ans;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	ll t;
	cin>>t;
	while(t--)
    {
        ll n;
        cin>>n;
        cout<<ans(n)<<endl;
    }
	return 0;
}
