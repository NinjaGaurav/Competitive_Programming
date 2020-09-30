#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<set>
 
using namespace std;
 
typedef long long int ll;
 
int main(){
	ll n;
	cin>>n;
	ll a1,a2,a3;
	cin>>a1>>a2>>a3;
	ll b1,b2,b3;
	cin>>b1>>b2>>b3;
	ll ans1=0;
	if(a1>=b1+b3){
		ans1+=a1-b1-b3;
		
	}
	else if(a2>=b1+b2){
		ans1+=a2-b1-b2;
		
	}
	else if(a3>=b2+b3){
		ans1+=a3-b2-b3;
	}
	ll ans2=0;
	ans2+=min(a1,b2);
	ans2+=min(a2,b3);
	ans2+=min(a3,b1);
	cout<<ans1<<" "<<ans2<<endl;
}

