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

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int fsize, ssize, ans=0, chk[]={-1};
    cin>>fsize>>ssize;
    vector<int> ref(ssize), buf(fsize,-1);
    for(int i=0;i<ssize;i++)
        cin>>ref[i];
    for(int i=0;i<ssize;i++){
        if(i==0){
            buf[i]=ref[i];
            ans++;
        }
        else {
            chk[0]=ref[i];
            auto adr=find(buf.begin(),buf.end(),chk[0]);
            if(adr==buf.end())
            {   chk[0]=-1;
                adr=find(buf.begin(),buf.end(),chk[0]);
                if(adr!=buf.end()){
                    buf[adr-buf.begin()]=ref[i];
                    ans++;
                }
                else{
                vector< pair<int,int> > buf2;
                for(int j=0;j<fsize;j++)
                    {
                        chk[0]=buf[j];
                        adr=find_end(ref.begin(),ref.begin()+i,chk,chk+1);
                        buf2.push_back(make_pair(adr-ref.begin(),buf[j]));
                    }
                sort(buf2.begin(),buf2.end());
                adr=find(buf.begin(),buf.end(),buf2[0].second);
                buf[adr-buf.begin()]=ref[i];
                ans++;
                }
            }
        }
        for(int i=0;i<fsize;i++)
            (buf[i]==-1)?cout<<"- ":cout<<buf[i]<<" ";
        cout<<endl;
    }
    cout<<"Total Page Faults: "<<ans;

	return 0;
}
