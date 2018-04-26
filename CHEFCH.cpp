#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
 
int main() {
	int t,c1=0,c2=0,p=0,m=0,i=0;
	char str[100000],copy1[100000],copy2[100000];
cin>>t;
for(;t!=0;t--)	
{	c1=0;
	c2=0;
	p=0;
	m=0;
	i=0;
	cin>>str;
	        for(;str[i]!='\0';i++)
	    {   if(str[i]=='+')
	        {p++;}
	        else if(str[i]=='-')
	        {m++;}
	   	}
	int k=strlen(str);
for(int j=0;j<k;j++)
{	if(j%2==0)
	{copy1[j]='+';
	}
	else
	{copy1[j]='-';
	}
}
copy1[k]='\0';
for(int j=0;j<k;j++)
{	
	if(j%2==0)
	{copy2[j]='-';
	}
	else
	{copy2[j]='+';
	}
}
copy2[k]='\0';
for(int j=0;j<=k;j++)
{	
	if(str[j]!=copy1[j])
	{c1++;}
}
for(int j=0;j<k;j++)
{	
	if(str[j]!=copy2[j])
	{c2++;}
}
if(c1>c2)
	cout<<c2<<endl;
else
	cout<<c1<<endl;
}
	return 0;
}
