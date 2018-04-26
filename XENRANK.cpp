#include <iostream>
using namespace std;
int main() {
	long long t,u,v,k,x1,y1=1,X=0,Y=1;
	
	
	cin>>t;
	while(t--)
	{   
	    cin>>u>>v;
	    k=u+v;
	   y1=1+k*(k+1)/2;
	    
	    
	    while(k!=v)
	    {
	        k--;
	        y1++;
	    }
	    cout<<y1<<endl;
	}
	return 0;
}
