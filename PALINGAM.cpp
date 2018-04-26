#include <iostream>
#include <algorithm>
using namespace std;
int fn(string a,string b,int l)
{
    for(int i=0;i<l;i++)
    {
        if(a[i]!=b[i])
        return 0;
        
    }
    return 1;
    
}
int main() {
    int T;
    cin>>T;
    while(T--)
    {   int D=0,E=0,l=1;
        string s,t;
        char s1[600],t1[600];
        cin>>s;
        cin>>t;
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        s1[0]=s[0];
        t1[0]=t[0];
        int it=0,is=0;
        for(int i=1;i<=s.length();i++)
        {
            if(i==s.length())
            s1[++is]='\0';
            if(s[i]!=s1[is])
            {
                s1[++is]=s[i];
            }
        }
        for(int i=1;i<=t.length();i++)
        {
            if(i==t.length())
            t1[++it]='\0';
            if(t[i]!=t1[it])
            {
                t1[++it]=t[i];
            }
        }
         if(fn(s1,t1,is))
        {  l=0;
            cout<<"B\n";
        }
        else if(std::includes(s.begin(), s.end(),t.begin(), t.end()))
        {   
            l=0;
             cout<<"A\n";
        }
        else if (std::includes(t.begin(), t.end(),s.begin(), s.end()))
        {    l=0;
            cout<<"B\n";
        }
        else
        {   
            for(int i=0;i<s.length()-1 && D!=-1;i++)
            {   
                if(s[i]==s[i+1])
                {
                    for(int k=0;k<it;k++)
                    {
                        if(s[i]==t1[k])
                        {    l=0;
                            D=-1;
                            cout<<"B\n";
                            break;
                        }
                    }
                    
                    if(D!=-1){
                    l=0;
                    cout<<"A\n";
                    break;
                    }
                }
                if(i+2==s.length())
                {    l=0;
                    cout<<"B\n";
                }
                
                
                
            }
             
        }
         if(l)
          cout<<"B\n";
    }
	return 0;
}
