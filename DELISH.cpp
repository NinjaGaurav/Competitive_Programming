#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
 
int main() {
    ll t,n;
    cin>>t;
    while(t--)
    {   
        cin>>n;
        ll a[n]={0},mAR[n]={0},MAR[n]={0},mAL[n]={0},MAL[n]={0};
        for(int i=0;i<n;++i)
            cin>>a[i];
        
           ll max_so_far = a[0];
           ll curr_max = a[0];
           MAL[0]=a[0];
   for (int i = 1; i < n; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
        MAL[i]=max(MAL[i-1],max_so_far);
       
   }
        
        
        
           max_so_far = a[n-1];
           curr_max = a[n-1];
           MAR[n-1]=max_so_far;
   for (int i = n-2; i >=0; i--)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
        MAR[i]=max(MAR[i+1],max_so_far);
       
   }       
        
        
        
       ll min_so_far = a[0];
       ll curr_min = a[0];
       mAL[0]=min_so_far;
        
   for (int i = 1; i < n; i++)
   {
        curr_min = min(a[i], curr_min+a[i]);
        min_so_far = min(min_so_far, curr_min);
        mAL[i]=min(min_so_far,mAL[i-1]);
       
   }
        
        
        
           min_so_far = a[n-1];
           curr_min = a[n-1];
           mAR[n-1]=min_so_far;
        
   for (int i = n-2; i >=0; i--)
   {
        curr_min = min(a[i], curr_min+a[i]);
        min_so_far = min(min_so_far, curr_min);
        mAR[i]=min(min_so_far,mAR[i+1]);    
       
   }
        ll ans=0;
        for(int i=0;i<n-1;i++)
        {
            ans=max(abs(MAR[i+1]-mAL[i]),ans);
            ans=max(abs(MAL[i]-mAR[i+1]),ans);
        }
        cout<<ans<<endl;
      //  cout<<MAL[0]<<" "<<MAL[1]<<endl<<MAR[0]<<" "<<MAR[1];
    }
    return 0;
}
