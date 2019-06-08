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

int main(){

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	while(t--)
    {
        ll p,s,prev=0,j=0,flag=1, maxphase=0,maxstate=0;
        cin>>p>>s;
        vi r(100005,0),c(100005,0),aux(200005,0);
        rep(i,0,p)
        {
            cin>>r[i];
            maxphase=max(maxphase,r[i]);
            if(r[i]==0)
            {
                i--;    //remove phase with 0 votes
                p--;    //adjust total valid phases
            }
        }
        rep(i,0,s)
        {
            cin>>c[i];
            if(c[i])
                ++maxstate;
            else
            {
                i--;        //remove state with 0 votes
                s--;        //total valid state reduced
            }
        }
        if(accumulate(all(r),0)!=accumulate(all(c),0) || maxphase>maxstate)
        {
            cout<<"NO\n";
            continue;
        }
        ll fix=0;
        sort(all(r),greater<ll>());
        sort(all(c),greater<ll>());
        rep(i,0,p)
        {
            if(prev+aux[i]+r[i]>0)
            {
                if(j>=s)
                {
                     if(fix<=0)
                     {
                        flag=0;
                        break;
                     }
                     else
                     {
                         if(fix>=prev+aux[i]+r[i])  //rhs is +ve, we need that more votes
                         {
                             ll tempo=prev+aux[i]+r[i];
                             fix-=tempo; //extra taken, deduct from fix
                             aux[i]-=tempo;
                             aux[i+1]+=(tempo);

                             prev+=aux[i];  //FINISHED

                         }
                         else
                         {
                            flag=0;
                            break;
                         }
                     }
                }
                else
                {
                    --aux[i];
                    ++aux[i+ c[j]]; 
                    ++j;
                    --i;
                    continue;
                }
            }
            else if(prev+aux[i]+r[i]<0) //filled extra in phase
            {   //IF EXCESS remove all VOTES ALLOTED and check fresh (4 4 1 3 1 3 2 2 2 2 case)
                ll tempo=prev+aux[i];
                fix+=abs(tempo);
                aux[i]-=(tempo);
                aux[i+1]+=(tempo);   //this term is -ve
                i--;
                continue;

            }
            else    // net == 0
            {
                ll tempo=prev+aux[i];
                fix+=abs(tempo);
                aux[i]-=(tempo);
                aux[i+1]+=(tempo);   //this term is -ve
                i--;
                continue;
            }

        }

        rep(ii,p,200005)    //check modifications caused by CRITICAL (redundant?)
        {
            if(prev+aux[ii]+0!=0)
            {
                flag=0;
                break;
            }
            prev+=aux[ii];
        }
        if(flag && j==s && fix==0)    //j==s all consumed
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
	return 0;
}

