#include <algorithm>
#include <iostream>
using namespace std;
#define ll unsigned long long int
int main() {
    ll m,n,ans=0;
    cin>>m>>n;
    ll A[m];
    for(ll i=0;i<m;i++)
        cin>>A[i];
    sort(A,A+m);
    for(ll i=m-1;n!=0;i--)
    {   
        if(A[i]>n)
        {
            ans+=(n*n+n)/2+1+i;
            n=0;    
        }
        else
        {
            ans+=(A[i]*A[i]+A[i])/2+1;
            n-=A[i];
        }
    }
    cout<<ans;
	return 0;
}
