#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {   int n,k;
        cin>>n>>k;
        int arr[2005];
        int c[2005][2005];
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++)
            {
                if(arr[i-1]<=j){
                    c[i][j]=max(c[i-1][j],arr[i-1]+c[i][j-arr[i-1]]);                    
                }
                else
                    c[i][j]=c[i-1][j];
            }
        }
        cout<<c[n][k]<<endl;
        
    }
    return 0;
}
