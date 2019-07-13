///////////////////////////////////
//      Author:  Gaurav Bholla   //
//      Institution: ASET        //
///////////////////////////////////
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
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector< vector<ll> > matrix;
bool check(vi arr, ll k, ll c)
{
    ll prev=0,i;

    for(i=0;i<sz(arr)-1;i++)
    {
        if(arr[i]<=c)
        {
            prev=0;
        }
        else
        {
            if(k<arr[i]-c)
            {
                return false;
            }
            ll moveable=arr[i]-prev;
            if(moveable>=arr[i]-c)
            {
                arr[i+1]+=arr[i]-c;
                prev=arr[i]-c;
            }
            else
                return false;
        }
    }
    if(arr[i]<=c)
        return true;
    else
        return false;
}
ll solve(vi arr, ll k)
{
    ll low=*min_element(all(arr)),high=*max_element(all(arr));
    ll ans = high,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(check(arr,k,mid))
        {
            ans = min(ans,mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
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
        ll n,k;
        cin>>n>>k;
        vi arr(n);
        rep(i,0,n)
            cin>>arr[i];
        cout<<solve(arr,k)<<endl;
    }
	return 0;
}
