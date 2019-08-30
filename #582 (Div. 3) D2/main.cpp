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
//#define endl '\n'
#define PB push_back
#define MP make_pair
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector< vector<ll> > matrix;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,k,ans=numeric_limits<ll>::max();
	cin>>n>>k;
	vi arr(n);
	unordered_map<ll,ll> M,F,COST;
	trav(a,arr)
	{
	    cin>>a;
	    M[a]++;
	    F[a]++;
	    COST[a]=0;
	    if(M[a]>=k)
	    {
	        cout<<0;
	        return 0;
	    }
	}
//	F=M;
	ll cf=1;
	for(int i=*max_element(all(arr));i>0;i/=2)
	{
        for(int j=1;j<=i;j++)
        {
            if(M[j]==0)
                continue;
            if(F[j/2]+M[j]>=k && F[j/2]<k)
            {

                ll tc = COST[j/2];
                ll tt = (k-F[j/2]);

                ans=min(ans,tc+tt*cf);

                F[j/2]+=M[j];
                M[j/2]+=M[j];
                COST[j/2]+=M[j]*cf;
                M[j]=0;
            }
            else
            {
                F[j/2]+=M[j];
                M[j/2]+=M[j];
                COST[j/2]+=M[j]*cf;
                M[j]=0;
            }
        }
        cf++;
	}
	cout<<ans;
	return 0;
}
