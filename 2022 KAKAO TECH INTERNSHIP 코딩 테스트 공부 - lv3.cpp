#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int maxalp = 0;
    int maxcop = 0;
    for(int i=0;i<problems.size();i++){
        maxalp = max(maxalp,problems[i][0]);
        maxcop = max(maxcop,problems[i][1]);
    }
    if(maxalp<alp && maxcop<cop){
        return 0;
    }
    alp = min(alp,maxalp);
    cop = min(cop,maxcop);
    int dp[maxalp+1][maxcop+1];
    for(int i=0;i<=maxalp;i++){
        for(int j=0;j<=maxcop;j++)
            dp[i][j] = 151;
    }
    dp[alp][cop]=0;
    for(int i=alp;i<maxalp+1;i++){
        for(int j=cop;j<maxcop+1;j++){
            int minalp = min(i+1,maxalp);
            int mincop = min(j+1,maxcop);
            dp[minalp][j] = min(dp[minalp][j],dp[i][j]+1);
            dp[i][mincop] = min(dp[i][mincop],dp[i][j]+1);
            for(auto tmp : problems){
                if(i>=tmp[0]&&j>=tmp[1]){
                    int nalp = min(maxalp,i+tmp[2]);
                    int ncop = min(maxcop,j+tmp[3]);
                    dp[nalp][ncop] = min(dp[nalp][ncop], dp[i][j]+tmp[4]);
                }
            }
        }
    }
    return dp[maxalp][maxcop];
}
