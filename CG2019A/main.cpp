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
bool valid(string XOR, ll i)
{
    while(i>0)
    {
        if(XOR[i%10]=='1')
            return false;
        i/=10;
    }
    return true;
}
ll solve(vi& arr, ll i, string XOR)
{

    if(i>=arr.size())
        return 0;
    ll rtrn=solve(arr,i+1,XOR); //skip and find
    if(valid(XOR,arr[i]))   //if valid check if better than skipping
    {
        string XOR2=XOR;
        //alter XOR2
            ll tmpi=arr[i];
            while(tmpi>0)
            {
                XOR2[tmpi%10]='1';
                tmpi/=10;
            }
        //
        return max( arr[i] + solve(arr,i+1,XOR2), rtrn );
    }
    else
        return rtrn;
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
        vi arr(n);
        trav(a,arr)
            cin>>a;
        cout<<solve(arr,0,"0000000000")<<endl;
    }
	return 0;
}
