#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
 string s=w;
    for(int i=0;i<w.size();i++)
    {
        if(i==w.size()-1)
                return "no answer";
        else if(w[i]<w[i+1])
            break;
    }
        
   // sort(s.begin(),s.end());
    do{
        if(s>w)
            return s;
    }while(next_permutation(s.begin(),s.end()));
   return "no answer" ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
