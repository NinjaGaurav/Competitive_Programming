#include <iostream>
using namespace std;
 
int main() {
	int t,c;
	char str[100];
	cin>>t;
	for(int i=0;i<t;i++)
	{   c=0;
		cin>>str;
	        for(int i=0;str[i]!='\0';i++)
	    {   if(str[i]=='A' || str[i]=='D' || str[i]=='O' || str[i]=='P' || str[i]=='Q' || str[i]=='R' )
	        {c++;}
	        else if(str[i]=='B')
	        {c+=2;}
	   	}
	cout<<c<<endl;
    }
	return 0;
}
