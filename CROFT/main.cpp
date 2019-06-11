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
        vector< pii > arr(n);
        rep(i,0,n)
            cin>>arr[i].first;
        rep(i,0,n)
            cin>>arr[i].second;
        sort(all(arr),[](auto& a, auto& b){ return a.first+a.second>b.first+b.second; });
        ll LARA_WAIFU=0,NIGGA=0;
        rep(i,0,n)
        {
            if(i&1)
            {
                NIGGA+=arr[i].second;
            }
            else
            {
                LARA_WAIFU+=arr[i].first;
            }
        }
        if(LARA_WAIFU>NIGGA)
            cout<<"First";
        else if(NIGGA==LARA_WAIFU)
            cout<<"Tie";
        else
            cout<<"Second";
        cout<<endl;
    }
	return 0;
}
