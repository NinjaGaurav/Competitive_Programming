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
    {
        ll n,k,x,y;

        cin>>n>>k;
        ll row[1000001]={0},col[1000001]={0},ctr=n-k;
        vector<ll> a,b;
        rep(i,0,k)
        {
            cin>>x>>y;
            row[x]=1;
            col[y]=1;
        }
        rep(i,1,n+1)
        {
            if(!row[i])
            a.push_back(i);
            if(!col[i])
            b.push_back(i);
        }

        cout<<ctr<<" ";
        rep(i,0,a.size())
        cout<<a[i]<<" "<<b[i]<<" ";
        cout<<endl;
    }


	return 0;
}
