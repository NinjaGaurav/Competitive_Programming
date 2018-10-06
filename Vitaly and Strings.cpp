//GAURAV, ALL HAIL THE COMMENTS!
#include <iostream>
#include <string.h>
using namespace std;
int main()
{   ios_base::sync_with_stdio(false);   //Saw on net to improve speed
    string s,t,n; //string is array of characters
    cin>>s;
    cin>>t;
    int z=0,j;
    n.resize(s.length());//found on net to resize string using standard function
    n=s;

   for(int k=0;k<s.length();k++)
   {
               if(n[s.length()-k-1]!='z')
            {   n[s.length()-k-1]=int(n[s.length()-k-1])+1;}
        else
            {   for(j=s.length()-k-1;n[j]>='z'&&j>0;j--,k++)//Gotta check this
                {   n[j]='a';}        //(found culprit of wrong n[j], it was happening because n[j+1] was modified, fixed it using 'g')<-This all is crap
                   
                    char ftw=(int)n[j]+1;
                    n[j]=ftw;//Wrong when i just use n[j] last resort was to use FTW
            }

        if((s.compare(n)<0)&&(t.compare(n)>0))//this function is like strcmp which compares 2 strings
        {   //this function returns -1 if smaller, 0 if equal and 1 if bigger
            cout<<n;
            z=1;
            break;
        }

    }
        if(z==0)//else this will be displayed
        cout<<"No such string"; // LOL In my previous program i outputted " No such string   ";

return 0;
}
