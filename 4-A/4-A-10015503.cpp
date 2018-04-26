#include <iostream>

using namespace std;

int main()
{   ios_base::sync_with_stdio(false);
    int w;
    cin>>w;
    if((w%2==0)&&(w>2))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}