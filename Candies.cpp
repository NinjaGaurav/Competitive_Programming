#include <bits/stdc++.h>

using namespace std;

// Greedy O(N) solution, can be solved in O(N*logN) or O(N) using sorting also
long candies(long n, vector<int> arr) {
    long init=0;
    vector<long> ans(n,1);
    for(long i=1;i<n;i++)
        if(arr[i]>arr[i-1])
            ans[i]=ans[i-1]+1;
    for(long i=n-1;i>0;i--)
        if(arr[i-1]>arr[i] && ans[i-1]<=ans[i])
            ans[i-1]=ans[i]+1;
    return accumulate(ans.begin(),ans.end(),init);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
