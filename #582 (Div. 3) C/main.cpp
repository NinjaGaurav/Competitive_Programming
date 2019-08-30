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

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll q;
	cin>>q;
	while(q--)
    {
        ll n,m;
        cin>>n>>m;
        vi arr(10);
        rep(i,0,10)
            arr[i]=(i+1)*m%10;
        ll tot = n/m;
        cout<<(tot/10*accumulate(all(arr),0LL))+(accumulate(arr.begin(),arr.begin()+tot%10,0LL)) <<endl;

    }
	return 0;
}
