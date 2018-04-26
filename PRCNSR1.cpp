#include <iostream>
 #include <stdio.h>
  #include<math.h>
using namespace std;
 
   
int main() {
	long long int t,n,k,p,a,s;
	scanf("%lld",&t);
  
	while(t--)
	{
	    scanf("%lld %lld",&n,&k);
        p=(k*(k+1)/2);
      s=k*k+k-2*n;
      a=(-1+sqrt(1+4*s))/2;
	    if(n>p)
	    printf("-1\n");
	    
	    else if(n==p) 
	     printf("0\n");
	    
	    else if(n<=k)
	    printf("%lld\n",k-1);//run this code
	
	    else
	   printf("%lld\n",a);
	    
	    n=0;k=0;
	}
	return 0;
}
