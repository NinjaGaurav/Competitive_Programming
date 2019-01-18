#include <bits/stdc++.h>
using namespace std;

struct process{
    int burst,arrival,waiting,turnaroundtime,id;
};
bool sortfn(const process& p1, const process& p2)
{
        if(p1.arrival==p2.arrival)
            return p1.burst<p2.burst;
        return p1.arrival<p2.arrival;
}
class comp
{
    public:
    int operator()(const process& p1, const process& p2)
    {
        return p1.burst > p2.burst;
    }
};
int main() {

	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cout<<"Enter Number of Processes: "<<flush;
	int n;
	cin>>n;
	priority_queue <process, vector<process>, comp > heap;
	vector<process> arr(n),brr;
	for(int i=0;i<n;i++)
    {
        cout<<"Enter Burst and Arrival time of Process "<<i+1<<": "<<flush;
        cin>>arr[i].burst>>arr[i].arrival;
        arr[i].id=i+1;
    }
    sort(begin(arr),end(arr),sortfn);
    int prev=max(0,arr[0].arrival);
    for(int i=0;i<arr.size() || heap.size()>0;)
    {
        if(i==0){

            arr[i].turnaroundtime= prev+arr[i].burst - arr[i].arrival;
            arr[i].waiting= arr[i].turnaroundtime - arr[i].burst;
            prev= prev+arr[i].burst;
            brr.push_back(arr[i]);
            i++;

        }
        else if(heap.size()==0)
        {
            prev=arr[i].arrival;
            arr[i].turnaroundtime= prev+arr[i].burst - arr[i].arrival;
            arr[i].waiting= arr[i].turnaroundtime - arr[i].burst;
            prev= prev+arr[i].burst;
            brr.push_back(arr[i]);
            i++;
        }
        else
        {
            process tmp=heap.top();
            heap.pop();
            tmp.turnaroundtime= prev+tmp.burst - tmp.arrival;
            tmp.waiting= tmp.turnaroundtime - tmp.burst;
            prev= prev+tmp.burst;
            brr.push_back(tmp);

        }
        while(i<arr.size() && arr[i].arrival<=prev)
        {
                heap.push(arr[i]);
                i++;
        }
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
