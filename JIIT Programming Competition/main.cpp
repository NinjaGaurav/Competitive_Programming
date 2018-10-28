/////////////////////////////////////
//	Author:			Gaurav Bholla & GOD ANKIT //
//	Institution: 	ASET, Noida //
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define repi(i, a, b) for(long long i = a; i >= (b); --i)
#define endl '\n'
#define MOD 1000000007
typedef long long ll;
ll sexy_multiplier(ll a, ll b)
{
	return ( (a % MOD) * (b % MOD) ) % MOD;
}
ll cal[100005]={0}; //we get 2*ceil(n/2) here or 2n
ll tmpodd=1;
int main() {
    memset(cal,0,sizeof(cal));
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    for(ll i=0;i<=100005;i++)       //till 2n
    {
        if(i==0)
        cal[i]=1;
        else
        {
            cal[i]=sexy_multiplier(cal[i-1],tmpodd);
            tmpodd+=2;
            tmpodd%=MOD;
        }

    }
  	ll n,t,ans;
    cin>>t;
    while(t--)
    {		ans=1;		//initially
    		cin>>n;
        ll arr[n];
        map<ll,ll> freq;
         rep(i,0,n)
         {
        		cin>>arr[i];
            freq[arr[i]]++;//okay
         }
        map<ll,ll>::iterator itr;

        for(itr=freq.begin();itr!=freq.end();itr++)
        {
         		ans=sexy_multiplier(ans,cal[(ll)(ceil((itr->second)/2.0))]);

        }
        cout<<ans%MOD<<endl;
    }

	return 0;
}
