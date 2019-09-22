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
bool chk(string& s)
{
    int r=0,c=0,n=0,m=0;
    trav(x, s)
    {
        if(x=='R')
            ++r;
        if(x>='0' && x<='9' && r && !c)
            n=1;
        if(x=='C' && r && n)
            ++c;
        if(x>='0' && x<='9' && r && c && n)
            m=1;
    }
    if(r==1&&c==1&&m&&n)
        return true;
    return false;
}
string A2B(string& s)
{
    char r,c;
    ll x,y,i=0,j;
    stringstream sss(s);
    sss>>r>>x>>c>>y;
    string ans;
    while(y>0)
    {
        j = y%26;
        if(j)
        {
            ans+=char( 'A' + j - 1 );
            y=y/26;
        }
        else
        {
            ans+='Z';
            y=y/26-1;
        }
    }
    reverse(all(ans));
    ans+=to_string(x);
    return ans;
}
string B2A(string& s)
{
    ll r=0,i=0,m=0;
    for(;!(s[i]>='0' && s[i]<='9');++i)
        r=r*26+ (s[i]-'A') + 1;
    for(;s[i];++i)
        m=m*10+(s[i]-'0');
    string ans=string("R")+to_string(m)+string("C")+to_string(r);
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
        if(chk(s))  //Type R NUM C NUM
        {
            cout<<A2B(s)<<endl;
        }
        else        //Type XY ROW_NO
        {
            cout<<B2A(s)<<endl;
        }
    }
	return 0;
}