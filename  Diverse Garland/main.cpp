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
void inc(char& c)
{
    switch(c)
    {
        case 'R': c='G'; break;
        case 'G': c='B'; break;
        case 'B': c='R'; break;
    }
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,ans=0;
	cin>>n;
	string s;
	cin>>s;
	rep(i,0,n-1)
	{
	    if(s[i]==s[i+1])
        {   ++ans;
            if(i+2<n)
            {
                do{
                    inc(s[i+1]);
                }
                while( s[i+1] == s[i+2]);
            }
            else
            {
                inc(s[i+1]);
            }
        }
	}
	cout<<ans<<endl;
	cout<<s<<endl;
	return 0;
}
