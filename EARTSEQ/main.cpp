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
const long long MAX_SIZE = 1000001;
vector<ll>isprimeffs(MAX_SIZE , true);
vector<ll>prime;
vector<ll>SmallestPrimeFactor(MAX_SIZE);

void manipulated_seive(ll N)
{
	isprimeffs[0] = isprimeffs[1] = false ;

	for (long long int i=2; i<N ; i++)
	{
		if (isprimeffs[i])
		{
			prime.push_back(i);
			SmallestPrimeFactor[i] = i;
		}
		for (long long int j=0;
			j < (ll)prime.size() &&
			i*prime[j] < N && prime[j] <= SmallestPrimeFactor[i];
			j++)
		{
			isprimeffs[i*prime[j]]=false;
			SmallestPrimeFactor[i*prime[j]] = prime[j] ;
		}
	}
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    manipulated_seive(611955);  //0-3332   max ||  buffer nos from 3350 to 3399 (3400th prime)
    //prime[i-1] stores ith prime, prime stores 50k
    vi odd,even;
    rep(i,0,3334)       // 0 to 3333 index, 3334 nos
    {
        if((i+1)&1) //odd?
            odd.push_back(prime[i]);
        else
            even.push_back(prime[i]);
    }
    vi magic;
    ll i=0,j=0,k=0;
    while(magic.size()!=50000)
    {
        magic.push_back(odd[i]);   i++;
        magic.push_back(even[(j+k)%even.size()]);  j++;
        if(i==odd.size())
        {
            i=0;
            j=0;
            k+=2;
        }

    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
       if(n<=3333)
        {
            rep(z,0,n-1)
                cout<<magic[z]*magic[z+1]<<" ";
            cout<<magic[n-1]*magic[0];
        }
        else
        {
            ll N=n-50;
            rep(z,0,N-1)
                cout<<magic[z]*magic[z+1]<<" ";

            cout<<magic[N-1]*prime[3350]<<" ";

            rep(z,3350,3399)    //z till 3398
                cout<<prime[z]*prime[z+1]<<" ";

            cout<<prime[3399]*prime[0]<<" ";
        }
        cout<<endl;
    }

	return 0;
}
