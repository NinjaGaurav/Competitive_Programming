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
int solve(vi arr,vi brr, ll n)
{   ll cnt=0,cycles=0;
    for(ll cur=0,i=0;cnt!=n;)
    {
        if(brr[cur]==0)
        {
            brr[cur]=1;
            cnt++;
            cur=arr[cur]-1;
            if(brr[cur]==0)
               continue;
            else
            {
                cycles++;
                cur=++i;
            }
        }
        else
        {
                cur=++i;
        }
    }
    return cycles;
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,cnt=0;
	cin>>n;
	vi arr(n);
	vi brr(n,0);
	rep(i,0,n)
	cin>>arr[i];
	cout<<solve(arr,brr,n)<<endl;
	for(ll cur=0,i=0;cnt!=n;)
    {
        if(brr[cur]==0)
        {
            brr[cur]=1;
            cnt++;
            cout<<cur+1<<" ";
            cur=arr[cur]-1;
            if(brr[cur]==0)
               continue;
            else
            {
                cout<<cur+1<<"\n";
                cur=++i;
            }
        }
        else
        {
                cur=++i;
        }
    }
	return 0;
}
