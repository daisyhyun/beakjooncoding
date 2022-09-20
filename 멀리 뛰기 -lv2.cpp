#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long dp[2001][3];
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][2]=0;
    dp[2][1]=1;
    dp[2][2]=1;
    dp[2][0]=2;
    for(int i=3;i<=n;i++){
        dp[i][1] = dp[i-1][0]%1234567;
        dp[i][2] = dp[i-2][0]%1234567;
        dp[i][0] = (dp[i][1]+dp[i][2])%1234567;
    }
    return dp[n][0]%1234567;
}
