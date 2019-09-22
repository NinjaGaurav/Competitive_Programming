/////////////////////////////////////
//	Author: Gaurav Bholla      //
//	Institution: ASET	   //
/////////////////////////////////////

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
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
void solve(ll n)
{
    vi doge;
    while(n)
    {
        doge.PB(n%10);
        n/=10;
    }
    reverse(all(doge));
    ll maxi=*max_element(all(doge));
    cout<<maxi<<endl;
    while(maxi--)
    {
        ll no=0;
        trav(a,doge)
        {
            if(a){
                no=no*10+1;
                --a;
            }
            else
                no*=10;
        }
        cout<<no<<" ";
    }
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n;
	cin>>n;
	solve(n);
	return 0;
}