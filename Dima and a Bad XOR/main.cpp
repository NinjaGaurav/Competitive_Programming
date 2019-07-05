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
	ll n,m,uni=0,yes=0;
	cin>>n>>m;
	vector< vi > arr(n,vector<ll>(m,0));
	unordered_map<ll,ll> MAP[n];
	trav(x, arr)
        trav(y, x)
            cin>>y;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            MAP[i][(arr[i][j])]=j;
        }
        uni+=MAP[i].size();
        if(sz(MAP[i])>1)
            yes=i;
    }
    if(uni==n)
    {
        uni=0;
        rep(i,0,n)
            uni^=arr[i][0];
        if(uni)
        {
            cout<<"TAK"<<endl;
            rep(i,0,n)
                cout<<1<<" ";
        }
        else
            cout<<"NIE";
    }
    else
    {
        uni=0;
        rep(i,0,n)
            uni^=arr[i][0];
        uni^=arr[yes][0];

        rep(j,0,m)
        {
            uni^=arr[yes][j];
            if(uni)
            {
                cout<<"TAK"<<endl;
                rep(k,0,n)
                    if(k==yes)
                        cout<<j+1<<" "; // 1 indexed
                    else
                        cout<<1<<" ";
                break;
            }
            uni^=arr[yes][j];
        }
        if(!uni)
            cout<<"NIE";
    }
	return 0;
}
