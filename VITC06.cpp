#include <iostream>
using namespace std;
#define ll unsigned long long int
int main() {
	// your code goes here
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n=n*(2*2+(n-1)*3)/2;
        cout<<n%1000007<<endl;
    }
	return 0;
}
