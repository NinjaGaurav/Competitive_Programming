#include <iostream>
using namespace std;
int main()
{	int t,p;
cin>>t;
for(int j=0;j<t;j++)
{	cin>>p;
	int c=0;
	for(;p>0;)
	{
	if(p>=2048)
	{c++;
	p=p-2048;}
	else if(p>=1024)
	{c++;
	p=p-1024;}
	else if(p>=512)
	{c++;
	p=p-512;}
	else if(p>=256)
	{c++;
	p=p-256;}
	else if(p>=128)
	{c++;
	p=p-128;}
	else if(p>=64)
	{c++;
	p=p-64;}
	else if(p>=32)
	{c++;
	p=p-32;}
	else if(p>=16)
	{c++;
	p=p-16;}
	else if(p>=8)
	{c++;
	p=p-8;}
	else if(p>=4)
	{c++;
	p=p-4;}
	else if(p>=2)
	{c++;
	p=p-2;}
	else
	{p=p-1;
	c++;}
	}
cout<<c<<endl;
}
return 0;
}
