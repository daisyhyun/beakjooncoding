#include<iostream>
#include<cstring>
using namespace std;
int dp[12];
int main(){
    int t,n;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        for(int i=4;i<=n;i++){
            dp[i] = dp[i-3]+dp[i-2]+dp[i-1];
        }
        cout << dp[n]<<"\n";
    }
}
