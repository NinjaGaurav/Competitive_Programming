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
#define FI first
#define SE second
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector< vector<ll> > matrix;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	vector<pair<string,ll>> arr(t);
	unordered_map<string,pii> M,N;
    rep(i,0,t)
    {
        string s;ll n;
        cin>>s>>n;
        arr[i]={s,n};
        if(M.find(s)==M.end())
        {
            M[s]={n,i};
        }
        else
            M[s]={M[s].FI+n,i};
    }
    ll ans=-1000000000LL;
    trav(itm,M)
    {
        if(itm.SE.FI>ans)
            ans=itm.SE.FI;
    }
    rep(i,0,t)
    {
        string s;ll n;

        s = arr[i].FI; n = arr[i].SE;
        if(N.find(s)==N.end())
        {
            N[s]={n,i};
        }
        else
            N[s]={N[s].FI+n,i};
        if(N[s].FI>=ans && M[s].FI==ans)
        {
            cout<<s<<endl; break;
        }
    }
	return 0;
}
