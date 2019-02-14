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
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll power(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}
ll modInverse(ll quo, ll m)
{
    return power(quo, m-2, m);
}

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k,m,NUM,DEN;
        cin>>n>>k>>m;
        if(m&1)
        {
            NUM= ( power(n,m/2+1,MOD) - power(n-1,m/2+1,MOD) + MOD )%MOD;
            DEN= power(n,m/2+1,MOD);
        }
        else
        {
            NUM= (((power(n,m/2,MOD) - power(n-1,m/2,MOD) + MOD )%MOD * (n+k))%MOD + power(n-1,m/2,MOD))%MOD;
            DEN= (power(n,m/2,MOD)*(n+k))%MOD;
        }

        cout<<((NUM%MOD)*((modInverse(DEN,MOD))%MOD))%MOD<<endl;

    }
	return 0;
}
