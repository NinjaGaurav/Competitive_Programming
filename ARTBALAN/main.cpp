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
bool prime[1000009];

void primegenerate(ll n)
{
    rep(i,0,1000009)
        prime[i]=true;

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	primegenerate(1000008);
	ll t;
	cin>>t;
	while(t--)
    {
        unordered_map<char,ll> m;
        ll ans=numeric_limits<ll>::max();
        string s;
        cin>>s;
        rep(i,0,sz(s))
            m[s[i]]++;
        auto start=m.begin();
        ll check=start->second;
        bool fl=true;
        for(auto mymap=m.begin();mymap!=m.end() && fl;mymap++)
            if(mymap->second!=check)
                fl=false;
        if(fl)
        {
            cout<<0<<'\n';
            continue;
        }
        vi arr;
        ll maxfreq=0,sum=0;
        for(auto mymap=m.begin();mymap!=m.end();mymap++)
        {
            sum+=mymap->second;
            maxfreq=max(maxfreq,mymap->second);
            arr.push_back(mymap->second);
        }
         if(prime[sum])
        {
            ll case1=numeric_limits<ll>::max(), case2=sum-maxfreq;
            if(sum<=26)
            {
                case1=0;
                for( auto mymap=m.begin();mymap!=m.end();mymap++)
                {
                    case1+=mymap->second-1;
                }
            }
            cout<<min(case1,case2)<<'\n';
        }
        else
        {
            sort(all(arr),greater<ll>());
            ll sub,add,temp;
            rep(i,1,27)
            {
                sub=add=temp=0;
                if(sum%i==0)
                {
                    ll bal=sum/i;
                    for(ll j=0; j<sz(arr) && j<i ;j++)
                    {
                        if(arr[j]>=bal)
                            sub+=abs(arr[j]-bal);
                        else
                            add+=abs(arr[j]-bal);
                    }
                    temp=sub-min(add,sub)+add;
                    ans=min(ans,temp);
                }
            }
            cout<<ans<<'\n';
        }
    }
	return 0;
}
