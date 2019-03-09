#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define PB push_back
#define MP make_pair
vector<int> dist(27,numeric_limits<int>::max()),parent(27,0),vis(27,0);
void printpath(int n)
{
    if(parent[n]==-1)
        cout<<char(n+64)<<" ";
    else
    {
        printpath(parent[n]);
        cout<<char(n+64)<<" ";
    }
}
int main() {

    char s,d;   // source destination
    int cost,NODES;   // cost
    vector< pair<int,int> > graph[27];//used to store graph (adjagency list)
    cin>>NODES;   //NO OF NODES
    string str;
    while(getline(cin>>ws,str)) //read input till EOF
    {   stringstream ss(str);
        ss>>s>>d>>cost;
       // cout<<int(s-'A'+1)<<" "<<d<<" "<<cost<<endl;
        graph[int(s-'A'+1)].PB(MP(cost,int(d-'A'+1)));    //build graph [cost,direction]
    }
   priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > heap;
    dist[1]=0;
    parent[1]=-1;
    heap.push(make_pair(dist[1],1));
    while(heap.size()>0)
    {
        pair<int,int> tmp=heap.top();
        heap.pop();
        if(vis[tmp.second])
            continue;
        vis[tmp.second]=1;
        for(int i=0;i<graph[tmp.second].size();i++)
        {
            if(!vis[graph[tmp.second][i].second])
            {
                    int newdist=dist[tmp.second]+ graph[tmp.second][i].first;
                    if(newdist<dist[graph[tmp.second][i].second])
                        {
                            dist[graph[tmp.second][i].second]=newdist;
                            parent[graph[tmp.second][i].second]=tmp.second;
                            heap.push(make_pair(dist[graph[tmp.second][i].second],graph[tmp.second][i].second));
                        }
            }

        }

    }
     cout<<dist[2]<<endl;  //1 is A, 2 is B, 3 is C and so on...
     printpath(2);   //1 is A, 2 is B, 3 is C and so on...
   return 0;
}
