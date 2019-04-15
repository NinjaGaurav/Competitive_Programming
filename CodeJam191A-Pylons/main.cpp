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
ll r,c,N;

bool solveBT(ll board[25][25], ll r1, ll c1, ll pos)
{   ll i;
    if(pos>=N)
        return true;
    rep(ii,0,N)     //r*c times we try at max for a number.
    {
        i=rand()%N;
        if( board[i/c][i%c]==0 && (r1==-1 || ((i/c)!=r1 && (i%c)!=c1 && (i/c)-(i%c)!=r1-c1 && (i/c)+(i%c)!=r1+c1) ) )
        {
            board[i/c][i%c]=++pos;
            if ( solveBT(board,i/c,i%c,pos) == true )
                return true;
            board[i/c][i%c]=0;
            --pos;
        }
    }
    return false;

}
struct xxx{ ll id,xa,ya;};
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	srand(time(0));
	ll t;
	cin>>t;
	rep(z,1,t+1)
	{   vector<xxx> ans;
	    cin>>r>>c;
        N=r*c;
        ll board[25][25]={0};
        if (!solveBT(board,-1,-1,0))
            cout<<"Case #"<<z<<": IMPOSSIBLE\n";
        else
        {
            cout<<"Case #"<<z<<": POSSIBLE\n";
            rep(i,0,r)
            {
                rep(j,0,c)
                {
                    xxx tmp;
                    tmp.id=board[i][j];
                    tmp.xa=i+1;
                    tmp.ya=j+1;
                    ans.PB(tmp);
                }

            }
            sort(all(ans),[](auto& A,auto& B){ return A.id<B.id; });
            rep(i,0,sz(ans))
                cout<<ans[i].xa<<" "<<ans[i].ya<<endl;
        }


	}
	return 0;
}
