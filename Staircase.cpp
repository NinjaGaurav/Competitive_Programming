#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    for(int k=1;k<=n;k++)
    {
         for(int i=n-k;i>0;i--)
            {
                 cout<<" ";
            }
        for(int j=0;j<k;j++)
            {
            cout<<"#";
              }
        cout<<endl;
    }
    return 0;
}
