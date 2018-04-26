#include <algorithm>
#include <iostream>
using namespace std;
 
int main() {
	int n,t;
	cin>>n>>t;
	int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
	while(t--)
	{
        int a,b;
        cin>>a>>b;
        int arr2[n];
        for(int i=0;i<n;i++)
        {
            arr2[i]=arr[i];
        }
        sort(arr2+a-1,arr2+b);
        cout<<arr2[a-1]<<endl;
	}
	return 0;
}
