/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET, Bijwasan //
/////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
class SegmentTreeRecLazy
{
public:
    SegmentTreeRecLazy(int n) : n(n)
    {
        data.assign(4 * n, 0);
        todo.assign(4 * n, 0);
    }

    SegmentTreeRecLazy(std::vector<int> const& v) {
        n = v.size();
        data.assign(4 * n, 0);
        todo.assign(4 * n, 0);
        build(v);
    }

    void build(std::vector<int> const& v, int id = 1, int l = 0, int r = -1) {
        if (r == -1)
            r = n;

        if (l == r - 1) {
            data[id] = v[l];
        } else {
            int m = (l + r) >> 1;
            build(v, id << 1, l, m);
            build(v, id << 1 | 1, m, r);
            data[id] = std::max(data[id << 1], data[id << 1 | 1]);
        }
    }

    int minimum(int x, int y, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
            return std::numeric_limits<int>::min();
        } else if (x <= l && r <= y) {
            return data[id];
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            return std::max(minimum(x, y, id << 1, l, m),
                            minimum(x, y, id << 1 | 1, m, r));
        }
    }

    void update(int x, int y, int addend, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) 
	{	//OUT OF RANGE VALUES IGNORED
        } 
	else if (x <= l && r <= y) {
            data[id] += addend;
            todo[id] += addend;
        }
	else {
            push(id, l, r);
            int m = (l + r) >> 1;
            update(x, y, addend, id << 1, l, m);
            update(x, y, addend, id << 1 | 1, m, r);
            data[id] = std::max(data[id << 1], data[id << 1 | 1]);
        }
    }

private:
    void push(int id, int l, int r)
    {
        data[id << 1] += todo[id];
        todo[id << 1] += todo[id];
        data[id << 1 | 1] += todo[id];
        todo[id << 1 | 1] += todo[id];
        todo[id] = 0;
    }

    int n;
    std::vector<int> data, todo;
};
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    int n;
    cin>>n;
    vector<int> arr(n);
	for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
        arr[i]+=i+1;
    }
    SegmentTreeRecLazy st(arr);
    cout << st.minimum(0,n) << '\n';
    for(int i=2;i<=n;i++)
    {
        st.update(0, n-i+1, 1);
        st.update(n-i+1, n-i+2, -n+1);
        st.update(n-i+2, n, 1);
        cout << st.minimum(0,n) << '\n';

    }
    return 0;

}
