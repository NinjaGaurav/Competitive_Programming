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
		ll n,x;
		cin>>n>>x;
		if(n<=2) cout<<1<<endl;
		else{
			ll t=n-2;
			if(t%x==0) t=t/x;
			else t=t/x+1;
			cout<<t+1<<endl;
		}
	}
}

