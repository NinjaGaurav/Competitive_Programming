#include <iostream>
using namespace std;
int main() {
    int n,t,X;
    cin>>t;
    while(t--)
    {   int a[1000];
        cin>>n;
        cin>>a[0];
        X=1;
        for(int i=1;i<n;i++){
            cin>>a[i];
           
        }
             for(int i=0;i<n/2;i++){
           
                    if(a[i]!=a[n-i-1])
                   {
                       X=0;
                       break;
                   }
            
             }            
            
            if(a[n/2]!=7)
            X=0;
            
        
                if(!X)
            {
                cout<<"no\n";
                continue;
            }
        cout<<"yes\n";
    }
	return 0;
}
