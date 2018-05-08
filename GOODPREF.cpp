/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET, Bijwasan //
/////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;  cin>>t;
	while(t--){
    string s;   cin>>s;
    ll n;  cin>>n;
    ll tp[1000]={0};
    ll ans=0,a=0,b=0;
    rep(i,0,s.size())
    {
        if(s[i]=='a')
            a++;
        else if(s[i]=='b')
            b++;
 
        tp[i]=b-a;
 
        if(a>b)
            ans++;
    }
    if(ans==0)            // ~O(1)
        ans=0;
    else if(a==b)         // ~O(1)
        ans*=n;
	else if(a<b)          // ~O(2*S)
    {
            ll mul=tp[s.size()-1];
            ans=0;
            rep(i,0,s.size())
            {
                if(tp[i]<0)
                {
                    ans+=min( ll(ceil(  double(abs(tp[i]))/mul  ) ), n);
                }
            }
    }
    else if(a>b)          // ~O(2*S)
    {
            ans=0;
            ll mul=tp[s.size()-1];
            rep(i,0,s.size())
            {
                if(tp[i]<0)
                    ans+=n;
                else if(tp[i]+(n-1)*mul>=0)
                {
                    continue;
                }
                else
                {
                    ll tx=ll(ceil(double(abs(tp[i]))/abs(mul)));
                    if(tp[i]%mul==0)
                        tx++;
                    ans+=((n)-tx);
                }
            }
    }
    cout<<ans<<"\n";
    }
    return 0;
}
