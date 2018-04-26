#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {     
           ll n,sum=0;
           cin>>n;
           ll dp[1001];
           vector<ll> H(n); //HOUSES or DIST
           vector<ll> K(n); //PUMPS
           for(ll c_i = 0; c_i < n; c_i++){
              cin >> H[c_i];
              H[c_i]*=2;// TOTAL PETROL = 2*DIST
           }
           for(ll c_i = 0; c_i < n; c_i++){
              cin >> K[c_i];
                
           }
            //DP[i] denotes min visits to station for dist = i kms
            for(int i=0;i<=1000;i++)
                dp[i]=1000000;           //INITALLY INF TIMES NEEDED TO FILL PETROL USING NO STATION
                
            dp[0]=0;    // 0 TIME NEEDED TO FILL PETROL FOR 0 LITRES/DIST
            for(int D=1;D<=1000;D++)   // TABLE CREATION FOR MIN STATION VISITS FOR 1 TO 1000 KM DIST
            {
                for(int i=0;i<n;i++)    //VISITING ALL STATIONS K[i]
                {
                    if(K[i]<=D) // FUEL=DIST
                    {
                        ll temp=dp[D-K[i]]+1;   // ASSUMING CURRENT PUMP IS USED FOR FUEL
                        if(temp<dp[D])
                        dp[D]=temp;
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                sum+=dp[H[i]];
            }
        cout<<sum<<endl;
    }
    return 0;
}
