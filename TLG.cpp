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
    ll p1,p2,t,t1=0,t2=0,winner,lead=0;
    cin>>t;
    rep(i,0,t)
    {
        cin>>p1>>p2;
        t1+=p1;
        t2+=p2;
        if(abs(t1-t2)>lead)
        {
            lead=abs(t1-t2);
            winner=(t1>t2)?1:2;
        }
    }
    cout<<winner<<" "<<lead;

	return 0;
}
