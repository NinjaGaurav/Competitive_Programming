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
    char popat[10]={'9','8','7','6','5','5','6','7','8','9'};
    while(t--)
    {
        string s;
        cin>>s;
        rep(i,0,s.size())
        {
            s[i]= popat[int(s[i]-'0')];
        }
        cout<<s<<endl;
    }
	return 0;
}
