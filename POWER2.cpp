#include <iostream>
using namespace std;
int main() {
	unsigned long long int t,n;
	cin>>t;
	for(;t>0;t--)
	{
	    cin>>n;
	    if((n%2==0)&&(n!=0))
	    cout<<"Yes\n";
	    else
	    cout<<"No\n";
	}
	return 0;
}
