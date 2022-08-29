#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int n;
vector<int> sns[1000000];
int dp[1000001][2];
int visited[1000001];
void fnd(int idx){
    visited[idx]=1;
    dp[idx][0]=0;
    dp[idx][1]=1;
    for(int i=0;i<sns[idx].size();i++){
        int next = sns[idx][i];
        if(visited[next]==0){
            fnd(next);
            dp[idx][0]+=dp[next][1];
            dp[idx][1]+=min(dp[next][0],dp[next][1]);
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        dp[i][0]=0;
        dp[i][1]=0;
        visited[i]=0;
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        sns[a].push_back(b);
        sns[b].push_back(a);
    }
    fnd(1);
    cout << min(dp[1][0],dp[1][1]);
}
