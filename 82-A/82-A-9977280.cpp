#include <iostream>
#include <math.h>
using namespace std;

int main()
{   ios_base::sync_with_stdio(false);
    string name[5] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
    long int n;
    cin>>n;
    int p=0;
    for(;5*(pow(2,p+1)-1)<n;p++);
    if((n>(5*(pow(2,p)-1)))&&(n<((5*(pow(2,p)-1))+pow(2,p)+1)))
        cout<<name[0];
    else if((n>((5*(pow(2,p)-1))+pow(2,p)))&&(n<((5*(pow(2,p)-1))+(2*pow(2,p))+1)))
        cout<<name[1];
    else if((n>((5*(pow(2,p)-1))+(2*pow(2,p))))&&(n<((5*(pow(2,p)-1))+(3*pow(2,p))+1)))
        cout<<name[2];
    else if((n>((5*(pow(2,p)-1))+(3*pow(2,p))))&&(n<((5*(pow(2,p)-1))+(4*pow(2,p))+1)))
        cout<<name[3];
    else
        cout<<name[4];

return 0;}