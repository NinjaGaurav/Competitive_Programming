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
	ll t;
	cin>>t;
	while(t--)
    {
        string tmp,s;
        cin>>s;
        int l=0,precnt=0;
        char prev='$';
        trav(ch, s)
        {
            if(ch!=prev)
            {
                if(precnt!=0){
                    tmp=to_string(precnt);
                    l+=tmp.size();
                }
                prev=ch;
                l++;
                precnt=1;
            }
            else
                precnt++;
        }
        tmp=to_string(precnt);
        l+=tmp.size();
        (l<sz(s))?cout<<"YES\n":cout<<"NO\n";
    }
	return 0;
}
