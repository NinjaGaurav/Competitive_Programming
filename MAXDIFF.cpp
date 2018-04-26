#include <bits/stdc++.h>
using namespace std;
int main() {
    long n,t,k,sum1=0,sum2=0,sum3=0;
    cin>>t;
    while(t--)
    {   sum1=0,sum2=0,sum3=0;
        cin>>n>>k;
        long a[n];
        
        for(long i=0;i<n;i++)
        {
            cin>>a[i];
            sum1+=a[i];
        }
        sort(a,a+n);
        for(long i=0;i<k;i++)
            {sum2+=a[i];
             sum3+=a[n-1-i];
            }
             
        cout<<max(abs(sum1-2*sum2),abs(sum3-(sum1-sum3)))<<endl;
    }
    return 0;
}
