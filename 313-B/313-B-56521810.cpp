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

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string s;
	cin>>s;
	vi doge(sz(s),0);
	rep(i,1,sz(s))
        if(s[i]==s[i-1])
            doge[i]=doge[i-1]+1;
        else
            doge[i]=doge[i-1];
	ll m,l,r;
	cin>>m;
	while(m--)
    {
        cin>>l>>r;
        cout<<doge[r-1]-doge[l-1]<<endl;
    }
	return 0;
}