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
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    ll n,x,y,ans=999999999;//<ll>::max();
    cin>>n>>x>>y;
    vector<ll> st(n),et(n),s(x),e(y);
    rep(i,0,n)
    {
        cin>>st[i]>>et[i];
    }
    rep(i,0,x)
    cin>>s[i];
    rep(i,0,y)
    cin>>e[i];
    sort(s.begin(),s.end());
    sort(e.begin(),e.end());
    rep(i,0,n)
    {
        ll t1,t2;
        t1=(lower_bound(s.begin(),s.end(),st[i])-s.begin());
        if(t1==x || s[t1]>st[i])
            t1--;
        //t1 -ve break
        t2=lower_bound(e.begin(),e.end(),et[i])-e.begin();
        if(t1<0 || t2==y)
            continue;
        else
        {
            if(e[t2]-s[t1]+1<ans)
                ans=e[t2]-s[t1]+1;
        }
    }
    cout<<ans;
	return 0;
}
