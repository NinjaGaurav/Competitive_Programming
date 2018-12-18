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

//	cin.sync_with_stdio(0); cin.tie(0);
	//cin.exceptions(cin.failbit);
	ll n,c,ans=-1,st=0,lo=1,hi,coins=1000;
	cin>>n>>c;
	hi=n;
	while(ans==-1){
          //  cout<<"\t\t\t"<<coins<<endl;
        if(hi-lo+1<=coins)
        {
            for(ll x=lo;x<=hi;x++)
            {
                cout<<"1 "<<x<<endl;
                --coins;
                cin>>st;

                if(st==1)
                {
                    ans=x;
                    break;
                }
            }
        }
        else
        {   ll prev=lo,x=lo,g=0;
            for(;x<=hi;)
            {
                cout<<"1 "<<x<<endl;
                --coins;
                cin>>st;
                if(st==1 && (x==lo || x==prev+1))
                {
                    ans=x;
                    break;
                }
                else if(st==1)
                {
                    lo=prev+1;
                    hi=x;
                    coins-=c;
                    cout<<"2"<<endl;
                    break;
                }
                else{
                    prev=x;
                    x+=pow(1.4,g);
                    ++g;
                    x=min(x,hi);
                }
            }
        }
	}
	cout<<"3 "<<ans<<endl;
    cout<<"\t\t\t"<<coins;
	return 0;
}
