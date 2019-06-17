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
ll F(ll n)
{
    ll ans=1;
    rep(i,1,n+1)
        ans*=i;
    return ans;
}
ll nCr(ll n, ll r)
{
    return F(n)/(F(n-r)*F(r));
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	// TRYING TO USE SET THEORY OF CLASS X
	ll e,m,h,x,y,z,XXX,ans;
	cin>>x>>e>>y>>m>>z>>h;
	char a,b,c;
	cin>>a>>b>>c;
	ll mx=0,my=0,mz=0;
	ans=nCr(x,e)*nCr(y,m)*nCr(z,h);
	cout<<ans<<endl;

    //COND 1

	XXX=(int(a-'A')+1);
	if(XXX<=x)
        mx++;
    else if(XXX<=x+y)
        my++;
    else
        mz++;
	XXX=(int(b-'A')+1);
	if(XXX<=x)
        mx++;
    else if(XXX<=x+y)
        my++;
    else
        mz++;

    ans=ans-nCr(x-mx,e-mx)*nCr(y-my,m-my)*nCr(z-mz,h-mz);

    //COND 2

    XXX=(int(c-'A')+1);
	if(XXX<=x)
        {
            mx++;
            ans-=nCr(x-1,e-1)*nCr(y,m)*nCr(z,h);
        }
    else if(XXX<=x+y)
        {
            my++;
            ans-=nCr(x,e)*nCr(y-1,m-1)*nCr(z,h);
        }
    else
        {
            mz++;
            ans-=nCr(x,e)*nCr(y,m)*nCr(z-1,h-1);
        }
    ans = ans + 1 + nCr(x-mx,e-mx)*nCr(y-my,m-my)*nCr(z-mz,h-mz);
    cout<<ans;
	return 0;
}
