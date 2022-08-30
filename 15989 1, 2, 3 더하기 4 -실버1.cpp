#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int dp[10001][4];
void fnd(){
    for(int i=4;i<=n;i++){
        for(int j=1;j<=3;j++){
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-2][1]+dp[i-2][2];
            dp[i][3] = dp[i-3][1]+dp[i-3][2]+dp[i-3][3];
            dp[i][0] = dp[i][1]+dp[i][2]+dp[i][3];
        }
    }
}
int main(){
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        memset(dp,0,sizeof(dp));
        dp[1][1]=1;
        dp[2][1]=1;
        dp[2][2]=1;
        dp[3][1]=1;
        dp[3][2]=1;
        dp[3][3]=1;
        dp[1][0]=1;
        dp[2][0]=2;
        dp[3][0]=3;
        fnd();
        cout << dp[n][0] << "\n";
    }
}
