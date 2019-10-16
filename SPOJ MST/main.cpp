#include <bits/stdc++.h>
// KRUSKAL
using namespace std;

vector < int > parent, depth;
void make_set(int i) {
    parent[i] = i;
    depth[i] = 0;
}
int find_set(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent[i]);
}
void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (depth[a] < depth[b])
            swap(a, b);
        parent[b] = a;
        if (depth[a] == depth[b])
            ++depth[a];
    }
}
struct edge
{
    int u,v,wt;
    bool operator<(edge& other)
    {
        return wt<other.wt;
    }
};
int main()
{
    int n,m;
    long ans=0;
    cin>>n>>m;
    parent.resize(n+1);
    depth.resize(n+1);
    for(int i=0;i<=n;i++)
        make_set(i);
    vector<edge> arr(m);
    for(int i=0;i<m;i++)
        cin>>arr[i].u>>arr[i].v>>arr[i].wt;
    sort(arr.begin(),arr.end());
    for(auto E: arr)
    {
        if(find_set(E.u)!=find_set(E.v))
        {
            ans+=E.wt;
            union_set(E.u,E.v);
        }
    }
    cout<<ans<<endl;
    return 0;
}
