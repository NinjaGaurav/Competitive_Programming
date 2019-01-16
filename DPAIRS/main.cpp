/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET		   //
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define repi(i, a, b) for(long long i = a; i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll m,n;
	cin>>m>>n;
	ll a[m],b[n],cnt=0;

    map<ll,ll> arr,brr;
    rep(i,0,m)
    {
        cin>>a[i];
        arr[a[i]]=i;
    }
    rep(i,0,n)
    {
        cin>>b[i];
        brr[b[i]]=i;
    }
	unordered_map<ll,ll> memo;
	auto aend=arr.end();
	aend--;
	for(auto ita=arr.begin();ita!=arr.end();ita++)
        for(auto itb=brr.begin();itb!=brr.end();itb++)
        {
            if(ita==aend)
            {
                if(memo[ ita->first + itb->first ]==0)
                {
                    memo[ita->first + itb->first]=1;
                    cout<<ita->second<<" "<<itb->second<<endl;
                    ++cnt;
                }

            }
            else if(ita==arr.begin()&&itb==brr.begin())
            {
                cout<<ita->second<<" "<<itb->second<<endl;
                ++cnt;
            }
            else if(itb==brr.begin())
            {
                if(memo[ ita->first + itb->first ]==0)
                {
                    memo[ita->first + itb->first]=1;
                    cout<<ita->second<<" "<<itb->second<<endl;
                    ++cnt;
                }
            }
            else
            {
                auto ta=ita; ta++;
                auto tb=itb; tb--;
                if(ita->first + itb->first <= ta->first + tb->first)
                    break;
                else if(memo[ ita->first + itb->first ]==0)
                {
                    memo[ita->first + itb->first]=1;
                    cout<<ita->second<<" "<<itb->second<<endl;
                    ++cnt;
                }
            }

            if(cnt==n+m-1)
                return 0;
        }
	return 0;
}
