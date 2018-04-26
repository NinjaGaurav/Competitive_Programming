#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main() {
	int t,i,g=0,z=0,sl=0;
	char s[10000];
	cin>>t;
	for(;t>0;t--)
	{
        cin>>s;
        for(i=0,sl=0;s[i]!='\0';i++)
	    {     sl++;
	    }
	    for(i=0;i<sl-1;i++)
	    { if(s[i]==s[i+1])
	        {z++;}
	    }
	    cout<<z<<endl;
	    z=0;
	}
	return 0;
}
