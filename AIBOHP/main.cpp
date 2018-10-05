/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET, Bijwasan //
// https://www.spoj.com/problems/AIBOHP/
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
ll memo[6500][6500];
ll solve(string &str, ll l, ll r)
{
        //base case
        if(memo[l][r]!=-1)
            return memo[l][r];
        if(l>=r)
            return memo[l][r]=0;
        else if(str[l]==str[r])
            return memo[l][r]=solve(str,l+1,r-1);
        else             //append lefts char at right         //rights char at left
            return memo[l][r]=min( 1 + solve(str,l+1,r) , 1 + solve(str,l,r-1)   );

}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	while(t--)
    {
        memset(memo,-1,sizeof(memo));
        string str;
        cin>>str;
        cout<<solve(str,0,str.size()-1)<<endl;
    }
	return 0;
}
