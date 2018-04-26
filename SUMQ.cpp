#include <iostream>
#include <math.h>
#include <algorithm>
#include<iomanip>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;
#define ll long long int
#define endl '\n'
const ll mod=1e9+7;
ll A[100001],B[100001],C[100001],sum=0,AS[100001],CS[100001];
ll bs( ll arr[],ll n, ll x)   //Binary search
{   
    if(x<arr[0])
    return -1;
    
    else if(x>=arr[n-1])
    return n-1;
    
   ll l=0,h=n-1,m,tag=0;
   
   while(l<=h)
   {
       m=(l+h)/2;
       if(arr[m]>x)
       {h=m-1;tag=-1;}
       
       else if(arr[m]<x)
       {l=m+1;tag=1;}
       
       else if(arr[m]==x)
       {
           while(arr[m]==x)
           m++;
           
           return --m;
       }
       
   }
   if(tag==1)
   {
       while(arr[l]>x)
       l--;
       
       return l;
   }
   else
   {
       while(arr[h]<x)
       h++;
       
       return --h;
       
       
   }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
        ll t;    
        ll p,q,r;
    cin>>t;
    while(t--)
    {
  		memset (A,0,100001);
        memset (B,0,100001);
 		memset (C,0,100001);
 		memset (AS,0,100001);
 		memset (CS,0,100001);
        cin>>p>>q>>r;
        for(long long int  i=0;i<p;i++)
        {
            cin>>A[i];
        }
 
       for(long long int  i=0;i<q;i++)
        {
            cin>>B[i];
        }
 
       for(long long int  i=0;i<r;i++)
        {
            cin>>C[i];
        }
 
        sort(A,A+p);
        AS[0]=A[0];
        for(ll i=1;i<p;i++)
        {
            AS[i]=AS[i-1]+A[i];  //store sum of X
            
 
        }
        sort(C,C+r);
        CS[0]=C[0];
        for(ll i=1;i<r;i++)
        {
            CS[i]=CS[i-1]+C[i];  //store sum of Z
            
        }
          mp::cpp_int bsum,bbi,bcxp1,bas,baxp1,bcs;
        ll ax=0,cx=0;
        bsum=0;
       for(long long int i=0;i<q;i++)  //loop for values in Y
       {
           ax=bs(A,p,B[i]);  //index of value <= Y[i] in X
           cx=bs(C,r,B[i]);  //index of value <= Y[i] in Z
 
 if(ax==-1||cx==-1)
 continue;
 
       bbi=B[i];bcxp1=cx+1;bas=AS[ax];baxp1=ax+1;bcs=CS[cx];
       
        bsum+=(bbi*(bcxp1*bas + baxp1*bcs + baxp1*bcxp1*bbi) + bas*bcs)%mod;
               
       }
 
  
        cout<<bsum%mod<<endl;
 
    }
 
	return 0;
}
