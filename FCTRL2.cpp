#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;
//thinking hugging buying unlucky huin
mp::cpp_int fact(mp::cpp_int sssssa)
{
    if(sssssa==1)
        return 1;
    if(sssssa==0)
        return 0;
    return sssssa * fact(sssssa-1);
}
int main()
{
    int tqwerty;
    cin>>tqwerty;
    while(tqwerty--)
    {
        mp::cpp_int sssssa;
        cin>>sssssa;
        cout<<fact(sssssa)<<endl;
    }
    return 0;
}
