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
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> matrix;

matrix mul(matrix A, matrix B) // 1-indexed
{
    matrix C(sz(A),vi(sz(B[0])));
    rep(i,1,sz(A))  rep(j,1,sz(B[0])) rep(k,1,sz(B))
        C[i][j]=( C[i][j] + ( A[i][k]*B[k][j] + MOD )% MOD + MOD ) % MOD;
    return C;
}
matrix mpow(matrix A, ll n)  // log(n) 1-indexed
{
    if (n==1)
        return A;
    if (n&1)
        return mul(A, mpow(A,n-1));
    matrix X = mpow(A,n/2);
    return mul(X,X);
}
ll solve(ll n)
{
    vi G{0,0,1,2};
    matrix T(3+1,vi(3+1,0));
    T[2][3]=T[1][2]=1;
    T[3][1]=-1;
    T[3][3]=2;

    if (n<=1)   //sum(0) means take nothing and sum(1) is 0 [F(1)=0]
        return 0;
    T = mpow(T,n-1);
    ll ans = 0;
    rep(k,1,sz(G))
        ans = (ans + (T[1][k]*G[k] + MOD)%MOD +MOD )%MOD;
    return ans;
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	while(t--)
    {
        ll n,m;
        cin>>n>>m;
        cout<<(solve(m+1)-solve(n)+MOD)%MOD<<endl;
    }
	return 0;
}
