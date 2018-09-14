//https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

#include <bits/stdc++.h>
//  j j j
//i
//i
//i
using namespace std;
int arr[1000][1000];
int d[1000][1000];
vector<string> split_string(string);
//2 means left || 3 means diagonally(up+left) || 4 means up
// Complete the longestCommonSubsequence function below.
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++)
        {
            if(a[i]==b[j])
            {
                arr[i+1][j+1]=arr[i][j]+1;
                d[i+1][j+1]=3;
            }
            else if(arr[i][j+1]>=arr[i+1][j])
            {
                arr[i+1][j+1]=arr[i][j+1];
                d[i+1][j+1]=4;                
            }
            else
            {
                arr[i+1][j+1]=arr[i+1][j];
                d[i+1][j+1]=2;                
            }
        }

    vector<int> ans(arr[a.size()][b.size()]);
    for(int i=ans.size(),x=a.size(),y=b.size();i>0;)
    {
            if(d[x][y]&1)
            {
                ans[--i]=a[x-1];
                x--;    y--;
            }
            else if(d[x][y]==4)
                x=x-1;
            else
                y=y-1;
                
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split_string(b_temp_temp);

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        int b_item = stoi(b_temp[i]);

        b[i] = b_item;
    }

    vector<int> result = longestCommonSubsequence(a, b);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
