#include <iostream>
#include <cmath>
using namespace std;
void sort(int a[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int k=0;k<n-1-i;k++)
        {
            if(a[k]>a[k+1])
            {
                temp=a[k];
                a[k]=a[k+1];
                a[k+1]=temp;
            }
        }
    }
}
int main() {
int t;
cin>>t;
for(int n=1;n<=t;n++)
{   int a[100],b[100];
    int k,sum=0;
    cin>>k;
    
    for(int i=0;i<k;i++)
    {   
       cin>>a[i];
    }
    
    for(int i=0;i<k;i++)
    {   
       cin>>b[i];
    }
    
    sort(a,k);
    sort(b,k);
    for(int i=0;i<k;i++)
    {   
       sum+=abs(a[i]-b[i]);
    }
    
    cout<<"Case "<<n<<": "<<sum<<endl;
    
}
	return 0;
}
