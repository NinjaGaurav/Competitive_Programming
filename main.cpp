///////////////////////////////////
//      Author:  Gaurav Bholla   //
//      Institution: ASET        //
///////////////////////////////////
#include <bits/stdc++.h>

using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }
template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p) { return os << "(" << p.first << ": " << p.second << ")";}
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v) { bool first = true; for(unsigned int i = 0; i < v.size(); i++) {
        if(!first) os << " "; os << v[i]; first = false; }
    return os; }
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::set<T>& v) { bool first = true; os << "{";
    for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if(!first) os << ", "; os << *ii; first = false; }
    return os << "}"; }
template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v) {
    bool first = true; os << "{";
    for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if(!first) os << ", "; os << *ii ; first = false; }
    return os << "}"; }
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::unordered_set<T>& v) {
    return os << std::set<T>(v.begin(), v.end()); }
template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::unordered_map<T1, T2>& v) {
    return os << std::map<T1, T2>(v.begin(), v.end()); }

long long mod_add(long long a, long long b, long long c){long long res=a+b;return(res>=c?res-c:res);}
long long mod_neg(long long a, long long b, long long c){long long res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
long long mod_mul(long long a, long long b, long long c){long long res=a*b;return(res>=c?res%c:res);}
template<typename T>T power(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T mod_power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod_mul(x,p,m);p=mod_mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repi(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define INF 1152921504606846976LL
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {

    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);



    return 0;
}
