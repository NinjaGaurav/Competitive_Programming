#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void fib(double n)
{
    double a=0,b=1,s=0;
    if(n==0)
        printf("IsFibo");
    else if(n==1)
        printf("IsFibo");
    else
    {
        for(;s<n;)
        { 
            s=a+b;
            a=b;
            b=s;
        }
        
        if(s==n)
            printf("IsFibo");
        else
           printf("IsNotFibo");
    }
}
    
int main() {
    double t,n;
    scanf("%lf",&t);
    while(t--)
    {
          scanf("%lf",&n);
          fib(n);
        printf("\n");

    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
