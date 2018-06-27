/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET, Bijwasan //
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    ll a,b,c,x;
    cin>>a>>b>>c;
    map<ll,ll> m;
    rep(i,0,a+b+c)
    {
        cin>>x;
        m[x]++;
    }
    map<ll,ll>::iterator it;
    x=0;
    for(it=m.begin();it!=m.end();it++)
        if(it->second>1)
            x++;
    cout<<x<<endl;
    for(it=m.begin();it!=m.end();it++)
        if(it->second>1)
        cout<<it->first<<endl;
	return 0;
}
