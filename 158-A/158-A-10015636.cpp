#include <iostream>

using namespace std;

int main()
{   ios_base::sync_with_stdio(false);
    int n,k,ns[100];
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>ns[i];
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        if((ns[i]>=ns[k-1])&&(ns[i]>0))
            c++;
    }
    cout<<c;
}