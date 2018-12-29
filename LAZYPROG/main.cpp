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
struct contract
{
    double a,b,d;
};
class xxx
{
public:
	int operator() (const contract& A, const contract& B)       //this is compulsary for priority queue
	{
		return A.a<B.a;       // children nodes shall be smaller than parent (max heap)
	}
};
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll t;
	cin>>t;
	while(t--)
    {
        ll n;
        cin>>n;
        priority_queue<contract, vector<contract> , xxx> heap; // xxx means the property children nodes should have
        contract a[n];
        rep(i,0,n)
        cin>>a[i].a>>a[i].b>>a[i].d;
        sort(a,a+n,[](auto& a, auto& b){return a.d<b.d;});
        double cost=0,time=0;

        rep(i,0,n)
        {
                                     //   cout<<cost<<" "<<time<<endl;

            heap.push(a[i]);
            if(a[i].b+time<=a[i].d)
                time+=a[i].b;
            else
            {       time+=a[i].b;
                    while(time>a[i].d)
                    {
                        contract x=heap.top();
                        heap.pop();
                        if(time - a[i].d >= x.b )       //max time u can save if its less then we need another pop
                        {
                            time-=x.b;
                            cost+=x.b/x.a;
                        }
                        else
                        {
                            cost+= ( time - a[i].d )/x.a;
                            x.b-= ( time - a[i].d );
                            time= a[i].d;   //done at deadline
                            heap.push(x);
                        }
                    }
            }
        }
        printf("%.2f\n",cost);      //.2 means show 2 decimal places after .

    }
	return 0;
}
