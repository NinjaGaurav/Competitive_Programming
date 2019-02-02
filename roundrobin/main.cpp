//	Author:			Gaurav Bholla  //
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
struct process{
    int burst,arrival,ct,waiting,turnaroundtime,id,b2;
};
bool sortfn(const process& p1, const process& p2)
{
        return p1.arrival<p2.arrival;
}

int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int qt;
	cout<<"Enter Quantum Time: "<<flush;
    cin>>qt;
    cout<<"Enter Number of Processes: "<<flush;
	int n,ctr=0,pos=0,prev=0;
	cin>>n;
    vector<process> arr(n),brr;
	for(int i=0;i<n;i++)
    {
        cout<<"Enter Burst & Arrival time of Process "<<i+1<<": "<<flush;
        cin>>arr[i].burst>>arr[i].arrival ;
        arr[i].id=i+1;arr[i].b2=arr[i].burst;
    }
    sort(begin(arr),end(arr),sortfn);
    queue<process> Q;
    process x;
    while(ctr!=n)
    {
        while(arr[pos].arrival<=prev && pos!=n)
        {
            Q.push(arr[pos++]);
        }

        if(Q.size()>0)
        {
            x=Q.front();
            Q.pop();
            for(int tm=0;tm<qt && x.burst!=0;tm++)
            {   prev++;
                x.burst--;
            }
            while(arr[pos].arrival<=prev && pos!=n)
            {
                Q.push(arr[pos++]);
            }
            if(x.burst)
                Q.push(x);
            else
            {
                x.ct=prev;
                x.turnaroundtime=x.ct-x.arrival;
                x.waiting=x.turnaroundtime-x.b2;
                brr.push_back(x);
                ctr++;
            }
        }
        else
            prev++;
    }
    double avgw=0,avgt=0;
    cout<<"PID\tWaiting Time\tTurnaround Time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<brr[i].id<<"\t\t"<<brr[i].waiting<<"\t\t"<<brr[i].turnaroundtime<<"\t"<<endl;
        avgw+=brr[i].waiting;
        avgt+=brr[i].turnaroundtime;
    }

    cout<<"Average waiting time = "<< avgw/n <<endl;
    cout<<"Average turn around time = "<< avgt/n <<endl;

	return 0;
}
