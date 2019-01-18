#include <bits/stdc++.h>
using namespace std;

struct process{
    int burst,arrival,waiting,turnaroundtime,id,completition;
};
bool sortfn(const process& p1, const process& p2)
{
        if(p1.arrival==p2.arrival)
            return p1.burst<p2.burst;
        return p1.arrival<p2.arrival;
}

int main() {

	cout<<"Enter Number of Processes: "<<flush;
	int n;
	cin>>n;
	vector<process> arr(n),brr(n);
	for(int i=0;i<n;i++)
    {
        cout<<"Enter Burst and Arrival time of Process "<<i+1<<": "<<flush;
        cin>>arr[i].burst>>arr[i].arrival;
        brr[i].burst=arr[i].burst;
        arr[i].id=i+1;
    }
    sort(begin(arr),end(arr),sortfn);
    int prev=0,ctr=0;
    for(;ctr!=arr.size();)
    {
        int minp=-1;
        for(int j=0;j<arr.size() && arr[j].arrival<=prev;j++)
        {
            if(minp==-1 || arr[minp].burst>arr[j].burst || arr[minp].burst==0)
                if(arr[j].burst!=0)
                    minp=j;
        }
        prev++;
        if(minp!=-1)
            if( --arr[minp].burst == 0 )
            {
                arr[minp].completition=prev;
                ctr++;
            }

    }
    double avgw=0,avgt=0;
    cout<<"PID\tWaiting Time\tTurnaround Time"<<endl;
    for(int i=0;i<n;i++)
    {
        arr[i].turnaroundtime= arr[i].completition - arr[i].arrival;
        arr[i].waiting= arr[i].turnaroundtime - brr[i].burst;
        cout<<arr[i].id<<"\t\t"<<arr[i].waiting<<"\t\t"<<arr[i].turnaroundtime<<"\t"<<endl;
        avgw+=arr[i].waiting;
        avgt+=arr[i].turnaroundtime;
    }
    cout<<"Average waiting time = "<< avgw/n <<endl;
    cout<<"Average turn around time = "<< avgt/n <<endl;
	return 0;
}
