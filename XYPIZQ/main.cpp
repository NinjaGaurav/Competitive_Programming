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
        ll n,type,a,b,c,x,y,div;
        cin>>n>>type>>a>>b>>c;

        if(type==1)
        {
                if(a!=c){
                y=2*n+1;
                x=y-c;
                div=__gcd(x,y);
                cout<<x/div<<" "<<y/div;
                }
                else
                {
                y=2*n+1;
                x=a;
                div=__gcd(x,y);
                cout<<x/div<<" "<<y/div;
                }
        }
        else if(type==2)
        {
                if(a!=c){
                y=2*n+1;
                x=y-2*b;
                div=__gcd(x,y);
                cout<<x/div<<" "<<y/div;
                }
                else
                {   if(c==n)
                    while(1);
                    else
                    cout<<0<<" "<<1;
                }
        }
        else if(type==3)
        {       if(a!=c){
                y=2*n+1;
                x=y-a;
                div=__gcd(x,y);
                cout<<x/div<<" "<<y/div;
                }
                else
                {
                y=2*n+1;
                x=a;
                div=__gcd(x,y);
                cout<<x/div<<" "<<y/div;
                }
        }
        else if(type==4)
        {
                if(a!=c){
                y=2*n+1;
                x=y-2*b;
                div=__gcd(x,y);
                cout<<x/div<<" "<<y/div;
                }
                else
                {   if(c==n)
                    while(1);
                    else
                    cout<<0<<" "<<1;
                }
        }
        cout<<endl;
    }
	return 0;
}
