#include <bits/stdc++.h>
using namespace std;
struct pro
{
  int pid,sz,no;  
};
int main() {
	int n,sz,m;
	cin>>n;
	pro tmp;
	vector<pro> first,best,worst;
	for(int i=0;i<n;i++)
	{
	    cin>>tmp.sz; tmp.pid=-1; tmp.no=i+1;
	    first.push_back(tmp);
	}
	best=first;
	worst=first;
	cin>>m;
	vector<int> arr(m);
	for(int j=0;j<m;j++)
	{
	    cin>>arr[j];
	}
	vector<int> ff(m,0),bf(m,0),wf(m,0);
	sort(best.begin(),best.end(),[](auto& a, auto& b){ return a.sz<b.sz; });
	sort(worst.begin(),worst.end(),[](auto& a, auto& b){ return a.sz>b.sz; });
	for(int i=0;i<m;i++)    // process
	{
	    for(int j=0;j<n;j++)
	        if(arr[i]<=first[j].sz && first[j].pid==-1)
	        {
	           first[j].pid=i; 
	           ff[i]=first[j].no;
	           break;
	        }
	    for(int j=0;j<n;j++)
	        if(arr[i]<=best[j].sz && best[j].pid==-1)
	        {
	           best[j].pid=i; 
	           bf[i]=best[j].no;
	           break;
	        }
	   	for(int j=0;j<n;j++)
	        if(arr[i]<=worst[j].sz && worst[j].pid==-1)
	        {
	           worst[j].pid=i; 
	           wf[i]=worst[j].no;
	           break;
	        }
	}
	cout<<"FIRST\n";
	for(int i=0;i<m;i++)
	{
	    if(ff[i]==0)
	    cout<<"Process "<<i+1<<" not allocated."<<endl;
	    else
	    cout<<"Process "<<i+1<<"("<<arr[i]<<")"<<" allocated to block "<<ff[i]<<" Size: "<<first[ff[i]-1].sz<<endl;
	}
	cout<<"BEST\n";
	for(int i=0;i<m;i++)
	{
	    if(bf[i]==0)
	    cout<<"Process "<<i+1<<" not allocated."<<endl;
	    else
	    cout<<"Process "<<i+1<<"("<<arr[i]<<")"<<" allocated to block "<<bf[i]<<" Size: "<<first[bf[i]-1].sz<<endl;
	}
	cout<<"WORST\n";
	for(int i=0;i<m;i++)
	{
	    if(wf[i]==0)
	    cout<<"Process "<<i+1<<" not allocated."<<endl;
	    else
	    cout<<"Process "<<i+1<<"("<<arr[i]<<")"<<" allocated to block "<<wf[i]<<" Size: "<<first[wf[i]-1].sz<<endl;
	}
	return 0;
}

