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

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n][n];
        ll number=1;
        for(ll i=0,j=0,mj=0;number<=n*n;mj++)
        {   if(mj<n)
            {   i=0;
                j=mj;
                while(j>=0)
                {
                    arr[i++][j--]=number++;
                }
            }
            else
            {
                i=mj-n+1;
                j=n-1;
                while(i<n)
                {
                    arr[i++][j--]=number++;
                }
            }
        }
        rep(i,0,n)
        {
            rep(j,0,n)
            cout<<arr[i][j]<<" ";

            cout<<endl;
        }
    }
	return 0;
}
