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
        vi arr(26,0);
        cin>>n;
        rep(j,0,n)
        {
            string s;
            cin>>s;
            rep(i,0,sz(s))
            {
                if(arr[s[i]-'a']==j)
                    arr[s[i]-'a']++;
            }
        }
        cout<<count(all(arr),n)<<endl;
    }
	return 0;
}
