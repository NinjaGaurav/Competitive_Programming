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
		ll n,m;
		cin>>n>>m;
		ll flag=0;
		for(ll i=0;i<n;i++){
			ll a,b,c,d;
			cin>>a>>b>>c>>d;
			if(b==c) flag=1;
		}
		if(m%2==1) cout<<"NO"<<endl;
		else{
			if(flag==1) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}

