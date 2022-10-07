#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n,m,x,y,d;
int arr[51][51];
int visited[51][51];
int nowsee;

/*
dir 0 -> 상
dir 1 -> 좌
dir 2 -> 후
dir 3 -> 우
*/
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int rule1(){
    int flag = 0;
    int tmpsee = nowsee;
    for(int i=0;i<4;i++){
        tmpsee++;
        if(tmpsee==4)
            tmpsee= 0;
        int nextx = x+dx[tmpsee];
        int nexty = y+dy[tmpsee];
        if(nextx>=0&&nextx<n&&nexty>=0&&nexty<m&&visited[nextx][nexty]==0&&arr[nextx][nexty]==0){
            x = nextx;
            y = nexty;
            visited[nextx][nexty] = 1;
            nowsee = tmpsee;
            flag = 1;
            break;
        }
    }
    return flag;
}

int rule2(){
    int tmpsee = nowsee-2;
    int flag =1;
    if(tmpsee<0)
        tmpsee+=4;
    int nextx = x+dx[tmpsee];
    int nexty = y+dy[tmpsee];
    if(nextx>=0&&nextx<n&&nexty>=0&&nexty<m&&arr[nextx][nexty]==0){
        x = nextx;
        y = nexty;
    }
    else{
        flag = 0;
    }
    return flag;
}

int movecar(){
    int res = 1;
    while(1){
        int k,kk;
        int findsee = nowsee;
        k = rule1();
        if(k==1)
            res++;
        if(k==0){
            kk= rule2();
            if(kk==0){
                return res;
            }
        }
        
    }
}


int main(){
    memset(visited,0,sizeof(visited));
    cin>>n>>m;
    cin>>x>>y>>d;
    if(d==0){
        nowsee =0;
    }
    if(d==1){
        nowsee =3;
    }
    if(d==2){
        nowsee =2;
    }
    if(d==3){
        nowsee =1;
    }
    visited[x][y] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp;
            cin>> tmp;
            arr[i][j] = tmp;
        }
    }
    cout << movecar();
}
