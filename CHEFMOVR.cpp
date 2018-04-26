#include <iostream>
#include <stdlib.h> 
using namespace std;
int main() {
    long long int n,d,t,X;
    cin>>t;
  
    while(t--)
    {   long long int a[200000];
        
        cin>>n>>d;
        cin>>a[0];
        long long int sum=a[0];
        for(int i=1;i<n;i++)
        {   cin>>a[i];
            sum+=a[i];
        }
        
        if(sum%n!=0)
        {
            cout<<"-1\n";
        }
        else{
        sum=sum/n;
        X=0;
        for(int i=0;i<n-d;i++)
        {
            if(a[i]<sum)
            {
                a[i+d]-=(sum-a[i]);
                X+=sum-a[i];
                a[i]=sum;
            }
            else if(a[i]>sum)
            {
                a[i+d]+=(a[i]-sum);
                X+=a[i]-sum;
                a[i]=sum;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(a[i]!=sum)
            {
             X=-1;
             break;
            }
        }
        
        cout<<X<<endl;
        }
    }
    
	return 0;
}
