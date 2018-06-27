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

    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,0,n)
    cin>>a[i];
    ll dep=0,ctr=0,t,y,u,o;
    t=y=u=o=-1;
    rep(i,0,n)
    {
        if(dep==0)
            ctr=0;
        if(a[i]&1)
            dep++;
        else
            dep--;
        if(dep>t)
        {
            t=dep;
            y=i;
        }
        ctr++;
        if(ctr>u)
        {
            u=ctr;
            o=i;
        }

    }
    cout<<t<<" "<<y+1<<" "<<u<< " "<<o-u+2;
	return 0;
}
