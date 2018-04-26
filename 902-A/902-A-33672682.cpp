#include <algorithm>
#include <iostream>
using namespace std;
#define ll unsigned long long int
ll chk[101],flag=1;
struct tp
{
  ll pos, y;  
};
int main() {
    ll m,n,i=0,N=0;
    cin>>n>>m;
    tp arr[n];
    while(n--)
       {    
            cin>>arr[i].pos>>arr[i].y;
            if(i>=1 && arr[i-1].pos==arr[i].pos)
            {   for(ll s=arr[i-1].y+1;s<=arr[i].y;s++)
                chk[s]++;
                i--;
            }   
            else
            {   N++;
               for(ll s=arr[i].pos;s<=arr[i].y;s++)
                chk[s]++; 
            }
            i++;
       }
    n=N;
    if(chk[0]==0 || chk[m]==0)
    {
        flag=0;
        cout<<"no";
    }
    for(ll i=1,x=1; flag && x<=m;x++)    
    {
        if(i<n && x==arr[i].pos)
        {   i++;
            if(chk[x]==1)
            {
                 flag=0;
                 cout<<"No";
                 break;
            }
        }
        else if(chk[x]==0)
        {
                 flag=0;
                 cout<<"NO";
                 break;
        }   
    }
        
    if(flag)
        cout<<"YES";

	return 0;
}