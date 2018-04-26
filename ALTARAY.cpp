#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n]={0},b[n]={0};
        for(ll i=0;i<n;i++)
            cin>>a[i];
        b[n-1]=1;
        for(ll i=n-2;i>=0;i--)
        {
            if(a[i]*a[i+1]<0)
                b[i]=b[i+1]+1; //DP?
            else
                b[i]=1;
        }
        for(ll i=0;i<n;i++)
            cout<<b[i]<<" ";
        cout<<endl;
        
    }
    return 0;
}
