#include <iostream>
using namespace std;
long int prime(long int i)
{	int j;
	for(j=2;j<=(i/j);j++)
            {
                if(!(i%j))
				return 0;
            }
        if(j>(i/j))
        {   return 1;
		}
	
}
 
int main() 
{
    long int n;
    cin>>n;
	if(n>=98690)//Improve speed by skipping 9,00,000 numbers
	{cout<<"1003001";
	 return 0;
	}
	for(long int p=n;p<=2000000;p++)
	{	long int rn=0,r=0;
		for(long int k=p;k>0;)
            {   r=k%10;
                k=k/10;
                rn=rn*10+r;
			}
		if(rn==p)
		{	if(prime(p))
			{	cout<<p;
				break;
			}
		}
	}
	return 0;
}
