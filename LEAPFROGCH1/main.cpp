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

int main() {

	freopen("input.txt","r",stdin);
    ll t;
    cin>>t;
    rep(i,1,t+1)
    {
        string s;
        cin>>s;
        ll count_b=0,flag=0;
        trav(a,s)
            if(a=='B')
                count_b++;
        if(sz(s)==2)
            flag = 0;
        else
        {
            if(count_b>=sz(s)/2 && count_b <=sz(s)-2)
                flag = 1;
            else
                flag = 0;
        }
        cout<<"Case #"<<i<<": ";
        (flag==1)?cout<<"Y\n":cout<<"N\n";
    }


	return 0;
}
