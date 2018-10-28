/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET, Bijwasan //
// https://www.spoj.com/problems/AIBOHP/
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define repi(i, a, b) for(long long i = a; i >= (b); --i)
#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll memo[5005][2];
ll solve(string &str, ll l, ll r)   // TOP DOWN O(N^2) space
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
    // O(N) space
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n;
	cin>>n;
	string str;
	cin>>str;
	// min of top item or right item so atmost 2 rows
	// if equal then top right item still atmost 2 rows
	// 0,2,4,... maps to 0 & 1,3,5,... maps to 1
	// 0 1 2 3 4 5
	// 0 1 0 1 0 1  hence we can use r%2
    rep(r,0,n)
        repi(l,r,0)
        {
            if(l>=r)
                memo[l][r%2]=0;
            else if(str[l]==str[r])
                memo[l][r%2]=memo[l+1][(r-1)%2];
            else
                memo[l][r%2]=1+min(memo[l][(r-1)%2],memo[l+1][r%2]);
        }
    cout<<memo[0][(n-1)%2];
	return 0;
}
