#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<set>
using namespace std;
typedef long long int ll;
int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++) cin>>a[i];
	ll t=0;
	ll count=0;
	map<ll,ll> m;
	//m.insert({a[0],0});
	for(ll i=0;i<n;i++){
		t=t+a[i];
		if(t==0 || m.find(t)!=m.end()){
			count++;
			m.clear();
			t=a[i];
		}
		m[t]=1;
	}
	cout<<count<<endl;
}

