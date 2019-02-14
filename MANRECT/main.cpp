/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET		   //
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define repi(i, a, b) for(long long i = a; i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {

    ll test;
    cin>>test;
    while(test--)
    {
        ll queryreply,first,second,third,fourth,chk,yu;

	cout<<"Q 0 0"<<endl;
        cin>>queryreply;
        first=queryreply;

	cout<<"Q 0 1000000000"<<endl;
        cin>>queryreply;
        third= -queryreply + 1000000000;

        cout<<"Q 1000000000 0"<<endl;
        cin>>queryreply;
        fourth= -queryreply + 1000000000 ;

	cout<<"Q 1000000000 1000000000"<<endl;
        cin>>queryreply;
        second= -queryreply + 2*1000000000;

        queryreply= (first+fourth)/2;
        cout<<"Q "<<queryreply<<" 0"<<endl;
        cin>>yu;
        cout<<"A "<<first-yu<<" "<<yu<<" "<<yu+fourth<<" "<<-yu-fourth+second<<endl;
        cin>>chk;
    }
	return 0;
}
