#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int n;
int res = 0;
void dfs(int visited[],int cnt,int p,vector<vector<int>> dungeons){
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            if(p>=dungeons[i][0]){
                visited[i] = 1;
                dfs(visited,cnt+1,p-dungeons[i][1],dungeons);
                visited[i] = 0;
            }
        }
    }
    res = max(res,cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int cnt = 0;
    n = dungeons.size();
    int visited[8] = {0,};
    dfs(visited,cnt,k,dungeons);
    return res;
}
