/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET, Bijwasan //
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

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int i=1,TA=0,FA=0;    string s;   unordered_map<char,int> m;    // initial ans 1
	cin>>s; s="X"+s;    //helper for 1-indexing
	rep(j,1,s.size())       //max len substring ending at index j including element at index j; starting pos 'i' is increased accordingly and is = 1 at start
	{
        if(i<=m[s[j]])
            i=m[s[j]]+1;
        m[s[j]]=j;
        TA=j-i+1;
        FA=max(FA,TA);
	}
	cout<<FA;
	return 0;
}
