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
struct pot{
ll s,e,p;
};
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	while(t--)
    {
        ll n;
        cin>>n;
        vector<pot> arr(n);
        rep(i,0,n)
        {
            cin>>arr[i].s>>arr[i].e>>arr[i].p;
            arr[i].e+=arr[i].s;
        }
        sort(begin(arr),end(arr),[](auto& a,auto& b){ return a.s<b.s;});
        //dp[i] stores max ans starting from item i
        //to do so correctly start building dp[i] for i=last item to first item
        ll dp[n];
        rep(i,0,n)
            dp[i]=arr[i].p;
        for(ll i=n-1;i>=0;i--)
        {
            for(ll j=i+1;j<n;j++)
            {
                if(arr[i].e<arr[j].s)
                    dp[i]=max(dp[i],dp[j]+arr[i].p);
            }
        }
        cout<<*max_element(dp,dp+n)<<endl;
    }
	return 0;
}
