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
	ll t;
	cin>>t;
	while(t--)
    {
        ll n,lx,d,ans=0,limR=-1000000,limL=1000000;
        cin>>n;
        unordered_map<ll,ll> line;	//map+iterator timed out
        rep(i,0,n)
        {
            cin>>lx>>d;
            line[lx]=d;
            limL=min(limL,lx);
            limR=max(limR,lx);
        }
        for(ll run=limL;run<=limR;)	//alternative: use iterator to get next filled locn
           {
               if(line[run]>=2)		// alternative: X reduces to X 1's if odd else X/2 1's 0 X/2 1's
               {
                   ans+=line[run]/2;
                   line[run-1]+=line[run]/2;
                   line[run+1]+=line[run]/2;
                   line[run]=(line[run])&1;
                   limR=max(limR,run+1);
                   --run;
               }
               else
                ++run;
           }
        cout<<ans<<endl;

    }
	return 0;
}
