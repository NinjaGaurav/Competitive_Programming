#include <bits/stdc++.h>

using namespace std;
int pa(string a,string b,int i)
{
    int len=a.length();
    
    a.erase(i,1);
    string A=a;
    reverse(A.begin(),A.end());
    b.erase(i,1);
    string B=b;
    reverse(B.begin(),B.end());
    if(a==A)
        return i;
    if(b==B)
        return len-i-1;
    
    return -1;
    
}
int palindromeIndex(string s){
    string S=s;
    string temp=s;
    reverse(temp.begin(),temp.end());
    if(s==temp)
        return -1;
    
    for(int i=0;i<S.length();i++)
    {
        if(s[i]!=temp[i])
        {
            return pa(s,temp,i); 
        }
    }
    return -1;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = palindromeIndex(s);
        cout << result << endl;
    }
    return 0;
}
