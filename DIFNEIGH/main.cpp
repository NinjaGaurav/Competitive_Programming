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

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
ll n,m,tx,ty;

ll arr[100][100];

ll valid(ll x, ll y)
{
    if(y>=0 && x>=0 && x<n && y<m && arr[x][y]!=0 && arr[x][y]==arr[tx][ty])
        return 1;
    return 0;
}

ll chk(ll x, ll y)
{   tx=x;   ty=y;
    if(valid(x,y-2) ||valid(x-1,y-1) ||valid(x-2,y) ||valid(x-1,y+1) )
        return 0;

    return 1;
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	while(t--)
    {
      cin>>n>>m;
      if(n*m<=2)                //SPECIAL CASE
      {
          cout<<1<<endl;
          rep(i,0,n)
                {
                    rep(j,0,m)
                    cout<<1<<" ";
                cout<<endl;
                }
      }
      else if(n==2 && m==2)     //SPECIAL CASE
      {
          cout<<2<<endl;
          rep(i,0,n)
                {
                    rep(j,0,m)
                    cout<<i+1<<" ";
                cout<<endl;
                }
      }
      else if(min(n,m)==1)      //SPECIAL CASE
      {
          ll bob[]={1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1};
          cout<<2<<endl;
          if(n<m)
          {
                rep(j,0,m*n)
                    cout<<bob[j]<<" ";
                cout<<endl;
          }
          else{
                 rep(j,0,m*n)
                    cout<<bob[j]<<endl;

          }
      }
      else if(min(n,m)<3)    //SPECIAL CASE
      {
          ll bob[2][50]={{1,1,2,2,3,3,1,1,2,2,3,3,1,1,2,2,3,3,1,1,2,2,3,3,1,1,2,2,3,3,1,1,2,2,3,3,1,1,2,2,3,3,1,1,2,2,3,3,1,1},
{2,3,3,1,1,2,2,3,3,1,1,2,2,3,3,1,1,2,2,3,3,1,1,2,2,3,3,1,1,2,2,3,3,1,1,2,2,3,3,1,1,2,2,3,3,1,1,2,2,3}};

            if(n<3)
            {
                ll ans=0;
                rep(i,0,n)
                    rep(j,0,m)
                    ans=max(ans,bob[i][j]);
                cout<<ans<<endl;
                rep(i,0,n)
                {
                    rep(j,0,m)
                    cout<<bob[i][j]<<" ";
                cout<<endl;
                }
            }
            else
            {
                ll ans=0;
                rep(i,0,m)
                    rep(j,0,n)
                    ans=max(ans,bob[i][j]);
                cout<<ans<<endl;
                rep(i,0,n)
                {
                    rep(j,0,m)
                        cout<<bob[j][i]<<" ";
                    cout<<endl;

                }
            }

      }
      else      //SUBSET OF 50x50 CONTAINS ANS,
      {         //but taking subset of R x R where R x R is smallest SQUARE MATRIX that encloses given m x n matrix and R is even
        ll bob=n,vegena=m;
        n=max(n,m)+max(n,m)%2;
        m=n;
        rep(i,0,100)
            rep(j,0,100)
                arr[i][j]=0;
        for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
        {
            arr[i][j]++;
            while(chk(i,j)==0)  // 0 means condition violated
            {
                ++arr[i][j];       // new colour assigned
            }
        }
        ll ans=0;
        rep(i,0,bob)
            rep(j,0,vegena)
                ans=max(ans,arr[i][j]);
        cout<<ans<<endl;
        rep(i,0,bob)
        {
            rep(j,0,vegena)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
      }
    }

	return 0;
}
