#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,m;
	    cin>>n>>m;
	    for(ll k=0 ; k<n*m ; ++k)
	    {
	        ll ans= ceil(n*m*1.0/(k+1));
			for(ll j=0 ; j<n*m ; j+=k+1 )
	       {
	           ll x=j/m,y=j%m;
	           if( (n*(y)+x)%(k+1) != 0)
	            ans++;
	       }
	       cout<<ans<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
