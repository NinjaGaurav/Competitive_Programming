#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
void sort_array(char array[],int length)
{
	int c,d;
	char temp;
	for(c=0;c<length;c++)
	{
		for(d=0;d<(length-c-1);d++)
		{
			if(array[d]>array[d+1])
			{
				temp=array[d];
				array[d]=array[d+1];
				array[d+1]=temp;
			}
		}
	}
}
int main()
{
	char a[500],b[500];
	cin>>a;
	cin>>b;
	int l1=strlen(a);
	int l2=strlen(b);
	if(l1!=l2)
	{
		printf("No\n");
	}
	else
	{
		sort_array(a,l1);
		sort_array(b,l2);
		int i,flag = 1;
		for(i=0;i<l1;i++)
		{
			if(a[i]!=b[i])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
