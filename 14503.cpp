#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define MAX 51
int arr[MAX][MAX];
int n,m;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int cnt;
int visited[MAX][MAX];

void dfs(int x, int y, int lok,int sum){
    for(int i=0;i<4;i++){
        int tmp = (lok+3-i)%4;
        int curx=x+dx[tmp];
        int cury=y+dy[tmp];
        if(curx>=0&&curx<n&&cury>=0&&cury<m&&visited[curx][cury]==0&&arr[curx][cury]==0){            visited[curx][cury]=1;
            dfs(curx,cury,tmp,sum+1);
        }
    }
    int tmp = lok+2<4 ? lok+2 : lok-2;
    int curx = x+dx[tmp];
    int cury = y+dy[tmp];
    if(curx>=0&&curx<n&&cury>=0&&cury<m){
        if(arr[curx][cury]==0)
            dfs(curx,cury,lok,sum);
        else{
            cout << sum;
            return;
        }

    }
}
int main(){
    memset(visited,0,sizeof(visited));
    cin>>n>>m;
    int r,c,d;
    cnt = 0;
    cin>>r>>c>>d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp;
            cin>>tmp;
            arr[i][j]= tmp;
        }
    }
    visited[r][c] = 1;
    if(arr[r][c]==0)
        cnt++;
    dfs(r,c,d,cnt);
    return 0;
}
