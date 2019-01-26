/////////////////////////////////////
//    Author:            Gaurav Bholla  //
//    Institution:     ASET           //
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
        ll n,f=1;
        cin>>n;
        vector<double> a(n);vector<double> b(n);
        rep(i,0,n)
            cin>>a[i];
        rep(i,0,n)
            cin>>b[i];
	    if(a[0]>0 || b[n-1]>0 || a[n-1]!=b[0]){
		    cout<<"No\n";
		    continue;
	    }
        double sht=numeric_limits<double>::max();
            rep(i,0,n)
                sht=min(sht,a[i]+b[i]);

            rep(i,0,n)
            {
                if(sht+b[i]<a[i] || sht+a[i]<b[i])
                {
                    f=0;
                    break;
                }
                if((a[i]==0 && i!=0) || (b[i]==0 && i!=n-1))    //distance has to be > 0 (+ve)
                {
                    f=0;
                    break;
                }
            }


        if(f)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
