#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int n;
double res;
double ewns[4];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int visited[30][30];
void dfs(int x,int y,int cnt,double perc){
    if(cnt==n){
        res+=perc;
        return;
    }
    for(int i=0;i<4;i++){
        int nexx = x+dx[i];
        int nexy = y+dy[i];
        if(ewns[i]!=0&&visited[nexx][nexy]==0){
            visited[nexx][nexy] = 1;
            dfs(nexx,nexy,cnt+1,perc*(ewns[i]/100));
            visited[nexx][nexy] = 0;
        }
    }
}
int main(){
    cin>>n>>ewns[0]>>ewns[1]>>ewns[2]>>ewns[3];
    res=0;
    memset(visited,0,sizeof(visited));
    visited[15][15]=1;
    dfs(15,15,0,1);
    cout.precision(10);
    cout << fixed << res;
}
