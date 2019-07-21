///////////////////////////////////
//      Author:  Gaurav Bholla   //
//      Institution: ASET        //
///////////////////////////////////
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
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector< vector<ll> > matrix;

ll solve(string s)
{
    ll ans=0;
    vi zero(s.size()),one(s.size());
    if(s[0]=='0')
        zero[0]++;
    else
        one[0]++;
    rep(i,1,sz(s))
    {
        zero[i]=zero[i-1];
        one[i]=one[i-1];
        if(s[i]=='1')
            one[i]++;
        else
            zero[i]++;
    }
    for(ll str=1;str+str*str<=s.size();str++)
    {   ll len=str+str*str;
        for(ll i=0;i+len<=s.size();i++)
        {
            if(i!=0){
            if((one[i+len-1]-one[i-1])*(one[i+len-1]-one[i-1])==(zero[i+len-1]-zero[i-1]))
                ans++;
            }
            else
            {
            if((one[len-1])*(one[len-1])==(zero[len-1]))
                ans++;
            }
        }
    }
    return ans;
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	while(t--)
    {
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }
	return 0;
}
