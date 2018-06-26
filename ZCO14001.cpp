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
    ll n,h;
    cin>>n>>h;
    vector<ll> boxes(n);
    rep(i,0,n)
    cin>>boxes[i];
    int c,pos=0,pick=0;
    while(1)
    {
        cin>>c;
        if(c==0)
            break;
        if(c==1 && pos>0)
            pos--;
        else if(c==2 && pos<n-1)
            pos++;
        else if(c==3 && pick==0 && boxes[pos]>0)
        {
            pick=1; boxes[pos]--;
        }
        else if(c==4 && pick==1 && boxes[pos]<h)
        {
            pick=0; boxes[pos]++;
        }
    }
    rep(i,0,n)
    cout<<boxes[i]<<" ";
	return 0;
}
