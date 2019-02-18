#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int fsize;
	cin>>fsize;
	int n;
	cin>>n;
	vector<int> ref(n,-1);
	for(int i =0;i<n;i++)
	{
	    cin>>ref[i];
	}
	int c=0;
	vector <int> frame(fsize,-1);
	for(int j=0;j<n;j++)
	{   
	    
	    auto it = find (frame.begin(), frame.end(), ref[j]);
        if (it == frame.end())
        {
            
            frame[c%fsize]=ref[j];
        
            c++;
            
        }
        cout<<ref[j]<<" | ";
        for(auto xc: frame)
        {
            xc==-1?cout<<"- ":cout<<xc<<" ";
        }
        cout<<endl;
          
	}
	cout<<"Page faults: "<<c<<endl;
	return 0;
}
