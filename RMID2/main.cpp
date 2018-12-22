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
	ll t,x,n,sm,bi;
	cin>>t;
	while(t--)
    {
        n=0;
        priority_queue<ll> maxheap;
        priority_queue<ll, vector<ll>, greater<ll> > minheap; // 3rd argument denotes which nos. will be the children,
                                                        //here children are greater than parent hence min heap.
        while(1)
        {
            cin>>x;
            if(x==0)
                break;
            else if(x==-1)
            {
                if(n&1) //  odd
                {
                        cout<<maxheap.top()<<endl;
                        maxheap.pop();
                }
                else
                {
                        cout<<maxheap.top()<<endl;
                        maxheap.pop();
                        maxheap.push(minheap.top());
                        minheap.pop();
                }
                n--;
            }
            else
            {   n++;
                if(minheap.size()==maxheap.size())
                {
                    if(minheap.size()==0)
                        maxheap.push(x);
                    else
                    {
                        sm=min(x,minheap.top());
                        bi=max(x,minheap.top());
                        minheap.pop();
                        minheap.push(bi);
                        maxheap.push(sm);
                    }
                }
                else
                {
                        sm=min(x,maxheap.top());
                        bi=max(x,maxheap.top());
                        maxheap.pop();
                        minheap.push(bi);
                        maxheap.push(sm);
                }
            }
        }

    }
	return 0;
}
