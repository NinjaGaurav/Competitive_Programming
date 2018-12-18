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
        ll n,x,Q,W,E,R,T,Y;
        cin>>n;
        ll a[n],XOR[n];
        cout<<"1 1 2 3"<<endl;
        cin>>Q;XOR[0]=Q;
        cout<<"1 1 2 4"<<endl;
        cin>>W;XOR[1]=W;
        cout<<"1 3 4 5"<<endl;
        cin>>E;XOR[2]=E;
        cout<<"1 3 4 6"<<endl;
        cin>>R;XOR[3]=R;
        a[4]=Q^W^E;
        a[5]=E^R^a[4];// 5
        for(ll i=7;i<=n;i++)
        {
            cout<<"1 "<<i-2<<" "<<i-1<<" "<<i<<endl;
            cin>>XOR[i-3];
            a[i-1]=XOR[i-3]^a[i-2]^a[i-3];

        }
        cout<<"1 "<<n<<" "<<n-1<<" "<<1<<endl;
        cin>>Q;
        a[0]=Q^a[n-1]^a[n-2];
        cout<<"1 2 5 "<<n<<endl;
        cin>>W;
        a[1]=W^a[n-1]^a[4];
        a[2]=XOR[0]^a[0]^a[1];
        a[3]=XOR[1]^a[0]^a[1];

        cout<<"2 ";
        for(ll m=0;m<n-1;m++)
            cout<<a[m]<<" ";
        cout<<a[n-1]<<endl;
        cin>>x;
        if(x==-1)
            return 0;
    }
	return 0;
}
