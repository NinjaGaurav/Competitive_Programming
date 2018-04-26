#include <iostream>
#include <cstdio>
using namespace std;
int main() 
{
    unsigned int t;
    scanf("%u",&t);
    for(;t!=0;t--)
    {
        long long int n=0;
        cin>>n;
        n=(((n)*(n+1))/2)+n;
        cout<<n<<endl;
    }
	return 0;
}
