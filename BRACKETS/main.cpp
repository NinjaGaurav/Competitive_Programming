/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET, Bijwasan //
// https://www.codechef.com/problems/BRACKETS
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t,maxb,b;
	cin>>t;
	while(t--)
    {   maxb=b=0;
        string a;
        cin>>a;
        rep(i,0,a.size()){
            if(a[i]=='(')
               ++b;
            else
                --b;
            maxb=max(maxb,b);
        }
        rep(i,0,maxb)
        cout<<'(';

        rep(i,0,maxb)
        cout<<')';

        cout<<endl;

    }
	return 0;
}
