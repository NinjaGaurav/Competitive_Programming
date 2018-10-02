#include <bits/stdc++.h>

using namespace std;

string counterGame(long n) {
int w=1;//w=1 Richard w=-1 Girl
    while(n!=1)
    {
        if(floor(log2(n))==ceil(log2(n)))
        {
            n/=2;
        }
        else
        {
            n=n-pow(2,floor(log2(n)));
        }
        w*=-1;
    }
    return w==1?"Richard":"Louise";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
 
