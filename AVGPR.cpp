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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    ll t,n,ans,x;
    cin>>t;
    while(t--)
    {   ans=0;
        cin>>n;
        ll arr[n];
        ll N=n;
        //UNORDERED MAP DOESN'T WORK IN CODECHEF BUT IT WORKS IN CODEBLOCKS,HACKERRANK,ETC
        map<ll,ll> m;
        map<ll,ll>::iterator it;
        map<ll,ll>::iterator itt;
        while(N--)
        {
            cin>>arr[N];
            ++m[arr[N]];
        }
        // FIRST IS THE NUMBER , SECOND ITS COUNT
        for(it=m.begin();it!=m.end();it++)          // SAME NUMBER CASE i.e.  5 5 5  ans is 3
        {
            if(it->second>1)
                ans+=(it->second-1)*(it->second)/2; 
              
        }
        for(it=m.begin();it!=m.end();it++)              // different NUMBER CASE
        {
                itt=it;
                itt++;
                for(;itt!=m.end();itt++)
                {
                    if((itt->first+it->first)&1)
                    continue;
                    if(m[(itt->first+it->first)/2])
                        ans+=(it->second)*(itt->second);
                }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
