#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    char word[101];
    for (; n>0; n--)
    {   cin>>word;
        if(strlen(word)<11)
            cout<<word<<endl;
        else
          { cout<<word[0]<<strlen(word)-2<<word[strlen(word)-1]<<endl;


            }

    }
return 0;
}