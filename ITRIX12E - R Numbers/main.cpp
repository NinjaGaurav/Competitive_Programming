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
int prime[19]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0};
int F2[10]={4,4,4,3,4,3,3,2,3,3};
matrix mul(matrix A, matrix B) // 0-indexed
{
    matrix C(sz(A),vi(sz(B[0])));
    rep(i,0,sz(A))  rep(j,0,sz(B[0])) rep(k,0,sz(B))
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
ll solve(ll n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 4;
    else if(n==2)
        return 33;
    matrix T(10,vi(10));
    rep(i,0,10)
        rep(j,0,10)
            if(i==0 || (prime[i+j]&&j))
                T[i][j]=1;
    T = mpow(T,n-2);
    ll ans = 0;
    rep(i,0,10)
        rep(j,0,10)
            ans = ( ans + (T[i][j]*F2[j])%MOD )%MOD;
    return ans;

}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	while(t--)
    {
        ll n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
	return 0;
}
