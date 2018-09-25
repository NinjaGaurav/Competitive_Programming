#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll memo[251][51];
ll getWays(ll n, vector < ll > c, ll m){
    // Complete this function
    if(n==0)
        return 1;
    if(n<0 || m>=c.size())
        return 0;
    if(memo[n][m]!=-1)
    {  // cout<<n<<' '<<m<<endl;
        return memo[n][m];
    }
    else{
        memo[n][m]=getWays(n-c[m],c,m)+getWays(n,c,m+1);
       //  cout<<n<<' '<<m<<endl;
        return memo[n][m];
    }
}

int main() {
    ll n;
    ll m;
    cin >> n >> m;
    vector<ll> c(m);
    for(int i=0;i<251;i++)
        for(int j=0;j<51;j++)
            memo[i][j]=-1;
    for(ll c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    cout<<getWays(n, c, 0);
    return 0;
}
