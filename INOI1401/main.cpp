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
#define MOD 20011
ll r,c,d;
ll memo[305][305][305][2];// 0-Right     1-Down;
ll arr[305][305];
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
  //  memset(memo,0,sizeof(memo));
	cin>>r>>c>>d;

	rep(i,0,r)
        rep(j,0,c)
            cin>>arr[i][j];

    repi(i,r-1,0)
        repi(j,c-1,0)
        {
            if(i==r-1 && j==c-1)
            {
                repi(k,d,0)
                {
                    memo[i][j][k][0]=1;
                  //  memo[i][j][k][1]=1;
                }
            }
            else if(arr[i][j]==0)
            {
                repi(k,d,0)
                {
                    memo[i][j][k][0]=0;
                    memo[i][j][k][1]=0;
                }
            }
            else
            {
                repi(k,d,1)
                {
                    memo[i][j][k][0]=(memo[i][j+1][k-1][0]+memo[i][j+1][d][1])%MOD;
                    memo[i][j][k][1]=(memo[i+1][j][k-1][1]+memo[i+1][j][d][0])%MOD;
                }
            }
        }
    cout<<(memo[0][0][d][0]+memo[0][0][d][1])%MOD;
	return 0;
}
