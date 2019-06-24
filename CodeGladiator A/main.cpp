/////////////////////////////////////
//	Author: Gaurav Bholla      //
//	Institution: ASET	   //
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repi(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define endl '\n'
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll count_distinct(string str)
{
    	unordered_set<char> ans;
    	for(auto ch: str)
            ans.insert(ch);
        return ans.size();
}
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll l,q;
	string str;
	cin>>l>>q;
	cin>>str;
	map<string,ll> items;
	rep(i,0,l)
	{
	    string temp;
            unordered_set<char> ans;
	    rep(j,i,l)
	    {
	        temp+=str[j];
	        ans.insert(str[j]);
	        items[temp]=ans.size();
	        //count here
	    }
	}
	ll cnt[sz(items)];
	ll ppp=0;
	trav(a,items)
	cnt[ppp++]=a.second;
	/*
	vector<string> dict;

	for(auto x: items)
        dict.PB(x);

        sort(all(dict));        //n2 logn2
*/
	rep(i,0,q)
	{
	    ll query;
	    cin>>query;
	    if(query>sz(items))
            cout<<-1<<endl;
        else
            cout<< cnt[query-1] <<endl;
	}
	return 0;
}
