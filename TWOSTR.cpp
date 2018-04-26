#include <iostream>
using namespace std;
int main() {
int t,c;
cin>>t;
while(t--)
{   char a[11],b[11];
    c=1;
    cin>>a;
    cin>>b;
    for(int i=0;a[i]!='\0';i++)
    {   
        if((a[i]!='?')&&(b[i]!='?')&&(a[i]!=b[i]))
        {
            c=0;
        }
        if(!c)
        {   cout<<"No\n";
            break;
        }
    }
    if(c)
    cout<<"Yes\n";
    
}
	return 0;
}
