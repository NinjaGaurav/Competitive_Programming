/////////////////////////////////////
//    Author:            Gaurav Bholla  //
//    Institution:     ASET           //
// https://www.hackerrank.com/contests/recode-5/challenges/thanos-reaches-earth/problem
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

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    vector< pii > cap;
    vector< vector<ll> > ppp(1000001);
    vi cnt(1000001);
    ll n;
    vi c(1000001);vi s(1000001);
    ll ans=numeric_limits<ll>::max();
    cin>>n;
    vi sum(n+1);sum[0]=0;
    rep(i,0,n)
        cin>>c[i];
    rep(i,0,n)
        cin>>s[i];
    rep(i,0,n)
    {
        cap.push_back(make_pair(s[i],c[i]));
        cnt[c[i]]++;
    }
    sort(all(cap)); //ascending strength
    rep(i,0,cap.size())
    {
        ppp[cap[i].second].push_back(i);
        //cout<<cap[i].second << " present at index "<<ppp[cap[i].second].back()<<endl;
    }
    rep(i,1,n+1){
    sum[i]=sum[i-1]+cap[i-1].first;
    //cout<<sum[i]<<endl;
    }
    rep(i,1,1000001)
    {
        if(cnt[i]>0)
           {
               ll pos=0,tans=0,dead=max((ll)0,n-(2*cnt[i]-1));
                tans=sum[dead];
                pos=dead;
                ll d2=0;
               rep(k,0,ppp[i].size())
                    if(ppp[i][k]<dead)
                        {
                            d2++;
                            tans-=cap[ppp[i][k]].first;
                        }

               dead = d2;
               while(dead>0 && pos!=n)
               {
                   if(cap[pos].second==i)
                    {
                        pos++;
                        continue;
                    }
                    else
                    {
                        tans+=cap[pos].first;
                        dead--;
                        pos++;
                    }

               }
               ans=min(ans,tans);
           }
    }
    cout<<ans<<endl;
    return 0;
}
