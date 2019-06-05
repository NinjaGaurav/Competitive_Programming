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

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	while(t--)
    {
        ll n,m,ans=0,n2=0;
        cin>>n>>m;
        vi orders(m);
        trav(a,orders)
            cin>>a;
        set<ll> doge;
        rep(i,0,sz(orders))
        {
            if(doge.find(orders[i])!=doge.end())    //found in set then skip
                continue;
            //else
            if(n2<n)
            {
                ++n2;
                doge.insert(orders[i]);
                ++ans;
            }
            else
            {
                ll tf=-1,tn=*(doge.begin());//first item in set
                trav(a,doge)
                {
                    ll cnt=-1;
                    rep(j,i+1,sz(orders))   //unfortunately farthest order is correct
                        if(a==orders[j]){   //and min freq of order is not :(
                            cnt=j;          //so this is just OPTIMAL PAGE REPLACEMENT
                            break;
                        }
                    if(cnt==-1){
                        tn=a;
                        break;
                    }
                    if(cnt>tf)
                    {
                        tf=cnt;
                        tn=a;
                    }
                }
                doge.erase(tn);
                doge.insert(orders[i]);
                ++ans;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
