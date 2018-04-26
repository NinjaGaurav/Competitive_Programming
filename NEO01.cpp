#include <iostream>
#include <math.h> 
#include <algorithm> 
#define ll long long int  
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,n,A[100001];
	cin>>t;
	while(t--)
	{	ll happiness=0;
		cin>>n;
		for(ll i=0;i<n;i++)	{
		
			cin>>A[i];
			
		
		}
		sort(A,A+n);
		if(A[n-1]<=0)
		{
				for(ll i=0;i<n && A[i]!=0;i++)	{
		
			
			happiness+=A[i];
			
		
		}
			
			
		}
		else
		{
			ll index=n-1,s1=0,s2=0,pc=0,s1h=0,s2h=0,flag=1;
			for(;A[index]>=0 && index>=0;index--)
			{	pc++;
				s1+=A[index];
			}
			s1h=s1*pc;
			while(s1h>=s2h && (n-pc)>=0)
			{
				s2h=s1h;
				if(index==-1){
				flag=0;
				break;
				}
				s1=s1+A[index--];
				pc++;
				s1h=s1*pc;
			}
			if(flag)
			index++;
			
			happiness=s2h>s1h?s2h:s1h;
			for(;index>=0 && n-pc>=0;index--)
			{  
				happiness+=A[index];
			}
		}
		cout<<happiness<<"\n";
	}
	
	
	return 0;
}
