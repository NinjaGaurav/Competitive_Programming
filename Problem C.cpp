#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<set>
 
using namespace std;
 
typedef long long int ll;
 
 
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll ans=INT_MAX;
		if(n==1) cout<<0<<endl;
		else if(n==2) cout<<1<<endl;
		else if(n==3) cout<<2<<endl;
		else if(n==4) cout<<2<<endl;
		else{
		
		for(ll i=1;i<sqrt(n)+1;i++){
			if(n%i==0){
				ans=min(ans,n/i+i-1);
			}
			else{
				ans=min(ans,n/i+i);
			}
		}
		cout<<ans-1<<endl;
		}
	}
	
	
}

