#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int n,m,x,y,k;
int arr[21][21];
int dice[7];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
queue<int> q;
int nowfloor,nowfront;
void initdice(){
    nowfloor = 1;
    nowfront = 6;
    memset(dice,0,sizeof(dice));
    /*
    ____
    | 5 |
    ________________
    |1 | 2| 3 | 4 | 
    _______________
    | 6 | 
    ____    
    */
}

void rolld(){
    int tmp = nowfloor;
    nowfloor = nowfront;
    if(tmp==1)
        nowfront=3;
    if(tmp==2)
        nowfront=4;
    if(tmp==3)
        nowfront=1;
    if(tmp==4)
        nowfront=2;
    if(tmp==5)
        nowfront=6;
    if(tmp==6)
        nowfront=5;
}
void rollu(){
    int tmp = nowfront;
    nowfront = nowfloor;
    if(tmp==1)
        nowfloor=3;
    if(tmp==2)
        nowfloor=4;
    if(tmp==3)
        nowfloor=1;
    if(tmp==4)
        nowfloor=2;
    if(tmp==5)
        nowfloor=6;
    if(tmp==6)
        nowfloor=5;
}

void rolll(){
    if(nowfront==1){
        if(nowfloor==2)
            nowfloor = 6;
        else if(nowfloor==4)
            nowfloor = 5;
        else if(nowfloor==6)
            nowfloor = 4;
        else if(nowfloor==5)
            nowfloor = 2;
    }
    if(nowfront==2){
        if(nowfloor==1)
            nowfloor = 5;
        else if(nowfloor==3)
            nowfloor = 6;
        else if(nowfloor==5)
            nowfloor = 3;
        else if(nowfloor==6)
            nowfloor = 1;
    }
    if(nowfront==3){
        if(nowfloor==2)
            nowfloor = 5;
        else if(nowfloor==4)
            nowfloor = 6;
        else if(nowfloor==5)
            nowfloor = 4;
        else if(nowfloor==6)
            nowfloor = 2;
    }
    if(nowfront==4){
        if(nowfloor==1)
            nowfloor = 6;
        else if(nowfloor==3)
            nowfloor = 5;
        else if(nowfloor==5)
            nowfloor = 1;
        else if(nowfloor==6)
            nowfloor = 3;
    }
    if(nowfront==5){
        if(nowfloor==1)
            nowfloor = 4;
        else if(nowfloor==2)
            nowfloor = 1;
        else if(nowfloor==3)
            nowfloor = 2;
        else if(nowfloor==4)
            nowfloor = 3;
    }
    if(nowfront==6){
        if(nowfloor==1)
            nowfloor = 2;
        else if(nowfloor==2)
            nowfloor = 3;
        else if(nowfloor==3)
            nowfloor = 4;
        else if(nowfloor==4)
            nowfloor = 1;
    }
}

void rollr(){
    
    if(nowfront==1){
        if(nowfloor==2)
            nowfloor = 5;
        else if(nowfloor==4)
            nowfloor = 6;
        else if(nowfloor==6)
            nowfloor = 2;
        else if(nowfloor==5)
            nowfloor = 4;
    }
    if(nowfront==2){
        if(nowfloor==1)
            nowfloor = 6;
        else if(nowfloor==3)
            nowfloor = 5;
        else if(nowfloor==5)
            nowfloor = 1;
        else if(nowfloor==6)
            nowfloor = 3;
    }
    if(nowfront==3){
        if(nowfloor==2)
            nowfloor = 6;
        else if(nowfloor==4)
            nowfloor = 5;
        else if(nowfloor==5)
            nowfloor = 2;
        else if(nowfloor==6)
            nowfloor = 4;
    }
    if(nowfront==4){
        if(nowfloor==1)
            nowfloor = 5;
        else if(nowfloor==3)
            nowfloor = 6;
        else if(nowfloor==5)
            nowfloor = 3;
        else if(nowfloor==6)
            nowfloor = 1;
    }
    if(nowfront==5){
        if(nowfloor==1)
            nowfloor = 2;
        else if(nowfloor==2)
            nowfloor = 3;
        else if(nowfloor==3)
            nowfloor = 4;
        else if(nowfloor==4)
            nowfloor = 1;
    }
    if(nowfront==6){
        if(nowfloor==1)
            nowfloor = 4;
        else if(nowfloor==2)
            nowfloor = 1;
        else if(nowfloor==3)
            nowfloor = 2;
        else if(nowfloor==4)
            nowfloor = 3;
    }
}

void rolldice(){
    initdice();
    int curx = x;
    int cury = y;

    while(!q.empty()){
        int dire = q.front();
        q.pop();
        int nextx = curx+dx[dire-1];
        int nexty = cury+dy[dire-1];
        if(nextx>=0&&nextx<n&&nexty>=0&&nexty<m){
            if(dire==1)
                rollr();
            if(dire==2)
                rolll();
            if(dire==3)
                rollu();
            if(dire==4)
                rolld();
            if(arr[nextx][nexty]!=0){
                dice[nowfloor]=arr[nextx][nexty];
                arr[nextx][nexty] = 0;
            }
            else{
                arr[nextx][nexty] = dice[nowfloor];
            }
            if(nowfloor==1){
                cout<<dice[3]<<"\n";
            }
            if(nowfloor==2){
                cout<<dice[4] << "\n";
            }
            if(nowfloor==3){
                cout<<dice[1] << "\n";
            }
            if(nowfloor==4){
                cout<<dice[2] << "\n";
            }
            if(nowfloor==5){
                cout<<dice[6] << "\n";
            }
            if(nowfloor==6){
                cout<<dice[5] << "\n";
            }
            curx = nextx;
            cury = nexty;
            
        }
    }
}



int main(){
    cin>>n>>m>>x>>y>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp;
            cin>>tmp;
            arr[i][j] = tmp;
        }
    }
    
    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        q.push(tmp);
    }
    
    rolldice();
}
