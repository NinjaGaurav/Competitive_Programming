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
#define MOD 1000000007
ll fact[200005];
ll mpow(ll a, ll b)
{
    if(b==0)
        return 1;
    else if(b&1)
        return mpow(a,b-1)*a%MOD;
    else
        return mpow(a*a%MOD,b/2);
}

int main() {
    fact[0]=1;
    for(ll i=1;i<200005;i++)
        fact[i]=( (i)%MOD * (fact[i-1]%MOD) )%MOD;
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	rep(i,0,t)
    {
        ll a,b,x,y;
        cin>>a>>b>>x>>y;
        x-=a;
        y-=b;
        ll ans=0;
        for(ll k=0;k<=min(x,y);k++)
        {
            ans+=(((((fact[x+y-k]*mpow(fact[y-k],MOD-2))%MOD )* mpow(fact[x-k],MOD-2))%MOD)*mpow(fact[k],MOD-2))%MOD;
            ans%=MOD;
        }
        cout<<"Case "<<i+1<<": "<<ans<<endl;
    }
	return 0;
}
