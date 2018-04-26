#include <iostream>
using namespace std;
int main() {
	long int t,n;
	long long m1=0,m2=0,s=0;
	cin>>t;
	for(;t>0;t--)
	{
	    cin>>n;
	    for(;n>0;n--)
	    {
	        cin>>m2;
	        if(m2>m1)
	        {
	            s+=(m2-m1);
	            m1=m2;
	        }
	        if(m2<=m1)
	        {
	            m1=m2;
	        }
	    }
	    cout<<s<<endl;
	    m1=0,m2=0,s=0;
	}
	return 0;
}
