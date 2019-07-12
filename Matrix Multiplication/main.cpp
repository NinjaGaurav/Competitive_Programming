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
typedef vector< vector<ll> > matrix;

matrix mul(matrix A, matrix B) // 1-indexed
{
    matrix C(sz(A),vi(sz(B[0])));
    rep(i,1,sz(A))  rep(j,1,sz(B[0])) rep(k,1,sz(B))
        C[i][j]=( C[i][j] + ( A[i][k]*B[k][j] )%MOD ) % MOD;
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

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	while(t--)
    {
        ll n,m;
        cin>>n>>m;
        matrix A(n+1,vector<ll>(n+1));
        rep(i,1,n+1) rep(j,1,n+1)
            cin>>A[i][j];
        A = mpow(A,m);
        rep(i,1,n+1)
        {
            rep(j,1,n+1)
                cout<<A[i][j]<<" ";
            cout<<endl;
        }
    }
	return 0;
}
