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
	string x;
	cin>>x;
	if(sz(x)<4)
        cout<<"NO";
    else
    {
        ll ans=0,i=0;
        for(i=1;i<sz(x) && !ans;i+=1)
            if(x[i]=='B' && x[i-1]=='A')
                for(i=i+2;i<sz(x) && !ans;i+=1)
                    if(x[i]=='A' && x[i-1]=='B')
                    {
                        ans=1;
                        break;
                    }
        for(i=1;i<sz(x) && !ans;i+=1)
            if(x[i]=='A' && x[i-1]=='B')
                for(i=i+2;i<sz(x) && !ans;i+=1)
                    if(x[i]=='B' && x[i-1]=='A')
                    {
                        ans=1;
                        break;
                    }
        if( ans )
            cout<<"YES";
        else
            cout<<"NO";

	}
	return 0;
}