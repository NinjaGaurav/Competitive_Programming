///////////////////////////////////
//      Author:  Gaurav Bholla   //
//      Institution: ASET        //
///////////////////////////////////
#include <bits/stdc++.h>
#include <unordered_map>
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
typedef int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector< vector<ll> > matrix;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	ll n;
	string s;
	cin>>n>>s;
	ll pre=0,sec=0,neg=0;
	trav(a,s)
	{
	    pre=(a=='(')?pre+1:pre-1;

	    if(a=='(')
            sec++;
        else
        {
            if(sec>0)
                --sec;
            else if(neg==0)
            {
                neg++;
            }
            else
            {
               pre=-1;
               break;
            }
        }

	}
	if(pre!=0)
    {
        cout<<"No";
    }
    else
        cout<<"Yes";

	return 0;
}
