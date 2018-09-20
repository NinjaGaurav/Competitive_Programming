#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;int d1=0,d2=0;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }
    for(int i=0,j=0;i<n;i++,j++)
        {
            d1+=a[i][j];
    }
    for(int i=0,j=n-1;i<n;i++,j--)
        {
            d2+=a[i][j];
    }
    cout<<abs(d1-d2);
    return 0;
}
