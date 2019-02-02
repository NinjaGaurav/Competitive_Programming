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
    {   char c;
        ll n,thor,ans=0,wt,fl=1;
        cin>>n>>thor;
        vi arr[26];
        rep(i,0,n)
        {
            cin>>c>>wt;
            arr[c-'a'].push_back(wt);
        }
        rep(i,0,26)
        {
            sort(all(arr[i]));
            while(!arr[i].empty() && thor<arr[i].back())
                arr[i].pop_back();
        }
        string s;
        cin>>s;
        for(ll i=0;i<sz(s) && fl;i++)
        {
            if(sz(arr[s[i]-'a'])<1)
                fl=0;
            else{
                ans+=arr[s[i]-'a'].back();
                arr[s[i]-'a'].pop_back();
            }
        }
        if(fl)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
	return 0;
}
