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

	ll n, d, e,ans=0;
	cin >> n >> d >> e;
	int hax = max(d,5*e)+2;
	int POS[hax]={0};
	POS[d]=1;
	POS[5*e]=1;
    POS[0]=1;
	rep(i, 1, n + 1)
	{

			if ((i - d >= 0 && POS[(i - d) % hax] == 1)|| (i - 5*e >= 0 && POS[(i - 5*e) % hax] == 1))
			{
 				POS[(i) % hax] = 1;
				ans = max(ans, i);
			}
			else
                POS[(i) % hax] = 0;
	}

	cout << n - ans << endl;

	return 0;
}
