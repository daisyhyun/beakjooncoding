#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n;
int dp[1000001];
void fnd(){
    for(int i=4;i<=n;i++){
        dp[i] = ((dp[i-1]+dp[i-2])%1000000009+dp[i-3])%1000000009;
    }
}
int main(){
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        memset(dp,0,sizeof(dp));
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        fnd();
        cout << dp[n] <<"\n";
    }
}
