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
ll F(ll n)	// Factorial calculator
{
    ll ans=1;
    rep(i,1,n+1)
        ans*=i;
    return ans;
}
ll nCr(ll n, ll r)	//nCr calculator
{
    if(n<0 || r<0)  //Need to modify the nCr formula since we couldn't calculate nCr if r is -ve (if we omit we get 1)
        return 0;
    return F(n)/(F(n-r)*F(r));
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	// TRYING TO USE SET THEORY
	ll e,m,h,x,y,z,XXX,ans;
	cin>>x>>e>>y>>m>>z>>h;
	char a,b,c;
	cin>>a>>b>>c;
	ll mx=0,my=0,mz=0;
	// Total ways is can be found using simple formula (nCr):
	ans=nCr(x,e)*nCr(y,m)*nCr(z,h);
	cout<<ans<<endl;
    //NOW WE SUBTRACT THE WAYS NOT POSSIBLE FOR 2nd Output (the 2 conditions given)
    //COND 1
	//find difficulty 
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
    //subtract from total ways
    ans=ans-nCr(x-mx,e-mx)*nCr(y-my,m-my)*nCr(z-mz,h-mz);

    //COND 2
	//find difficulty & subtract
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
    // add one since we can use one question only once and add the part that was subtracted twice i.e. was common in conditions 1 & 2
    ans = ans + 1 + nCr(x-mx,e-mx)*nCr(y-my,m-my)*nCr(z-mz,h-mz);
    cout<<ans;
	return 0;
}
