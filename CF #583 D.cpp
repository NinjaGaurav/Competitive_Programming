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
typedef int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector< vector<char> > matrix;
ll m, n, found=0;
void kaarigar(matrix& MAP, ll i, ll j)
{
	if (found || i>=n || j>=m)
		return;
	if (i == n - 1 && j == m - 1)
	{
		MAP[i][j]++;
		found = 1;
		return;
	}
	if (MAP[i][j] != '0')
		MAP[i][j] = '#';

	if(i<n-1 && MAP[i+1][j] != '#')
		kaarigar(MAP, i + 1, j);

	if (j<m-1 && MAP[i][j+1] != '#')
		kaarigar(MAP, i, j + 1);
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	cin >> n >> m;
	matrix MAP(n, vector<char>(m));
	rep(i, 0, n)
		rep(j, 0, m)
			cin >> MAP[i][j];
	MAP[0][0] = MAP[n - 1][m - 1] = '0';
	kaarigar(MAP, 0, 0);
	if (MAP[n - 1][m - 1] == '0')
	{
		cout << "0";
	}
	else
	{
		found = 0;
		kaarigar(MAP, 0, 0);
		(MAP[n - 1][m - 1] == '1') ? cout << "1" : cout << "2";
	}
	return 0;
}
