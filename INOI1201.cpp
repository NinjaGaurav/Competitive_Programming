 #include <iostream>
    #include <algorithm>
    using namespace std;
    struct id{
    long int c,p,d,s,t;
    };
    
 
void MAX_HEAPIFY(id a[], long int i, long int n)
{
    long int l,r,largest;
	id loc;
    l=2*i;
    r=(2*i+1);
    if((l<=n)&&a[l].s>a[i].s)
       largest=l;
    else
       largest=i;
    if((r<=n)&&(a[r].s>a[largest].s))
       largest=r;
    if(largest!=i)
    {
         loc=a[i];
         a[i]=a[largest];
         a[largest]=loc;
         MAX_HEAPIFY(a, largest,n);
    }
}
void BUILD_MAX_HEAP(id a[], long int n)
{
    for(long int k = n/2; k >= 1; k--)
    {
        MAX_HEAPIFY(a, k, n);
    }
}
void HEAPSORT(id a[], long int n)
{
 
    BUILD_MAX_HEAP(a,n);
    long int i;
	id temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        MAX_HEAPIFY(a, 1, i - 1);
    }
}
    int main() {
     
        long int n;
        cin>>n;
        id a[n+4];
        for(long int i=1;i<=n;i++)
        {
            cin>>a[i].c>>a[i].p>>a[i].d;
            a[i].s=a[i].p+a[i].d;
            a[i].t=a[i].p+a[i].d+a[i].c;
        }
         	 
   			 HEAPSORT(a, n);
     
   long int buffer,max;
  buffer=0;
  max=a[n].t;
       
  for(long int t=n-1;t>=1;t--)
  { buffer+=a[t+1].c;
  
    if(max<a[t].t+buffer)
    {
        max=a[t].t+buffer;
    }
    
  }
  cout<<max;  
    	return 0;
    }
      
