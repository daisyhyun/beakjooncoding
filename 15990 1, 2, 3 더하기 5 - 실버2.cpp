#include<iostream>
#include<cstring>

using namespace std;
int n;
int dp[100001][4];

void fnd(){
    for(int i=4;i<=n;i++){
        dp[i][1] = (dp[i-1][2]+dp[i-1][3])%1000000009;
        dp[i][2] = (dp[i-2][1]+dp[i-2][3])%1000000009;
        dp[i][3] = (dp[i-3][1]+dp[i-3][2])%1000000009;
    }
}
int main(){
    int k;
    cin>>k;
    for(int tc=1;tc<=k;tc++){
        cin>>n;
        memset(dp,0,sizeof(dp));
        dp[1][1] =1;
        dp[2][2] =1;
        dp[3][1] = 1;
        dp[3][2] = 1;
        dp[3][3] = 1;
        fnd();
        cout << ((dp[n][1]+dp[n][2])%1000000009+dp[n][3])%1000000009 << "\n";
    }
}
