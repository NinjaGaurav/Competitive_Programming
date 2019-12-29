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
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector< vector<ll> > matrix;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n;
	cin>>n;
	vi arr(n);
    trav(a,arr){
        cin>>a;
        --a;
    }

    vi send(n,0); vi rec(n,0);
    rep(i,0,n)
    {
        if(arr[i]>=0)
        {
            send[i]=1;
            rec[arr[i]]=1;
        }
    }
    vi both,s,r;
    rep(i,0,n)
    {
        if(send[i]+rec[i]==0)
            both.PB(i);
        else if(send[i]==0)
            s.PB(i);
        else if(rec[i]==0)
            r.PB(i);
    }
    while(sz(both) && sz(r))
    {
        arr[both.back()]=r.back();
        r.pop_back();
        r.PB(both.back());
        both.pop_back();
    }
    while(sz(both) && sz(s))
    {
        arr[s.back()]=both.back();
        s.pop_back();
        s.PB(both.back());
        both.pop_back();
    }
    while(sz(r) && sz(s))
    {
        arr[s.back()]=r.back();
        s.pop_back();
        r.pop_back();
    }
    if(sz(both)>=2)
    {
        for(int i=0;i<both.size();i++)
            arr[both[i]]=both[(i+1)%sz(both)];
    }
    trav(a,arr)
        cout<<a+1<<" ";
    cout<<endl;
    cin>>arr[0];
	return 0;
}
