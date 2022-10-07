#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n,m;
int arr[8][8];
int realarr[8][8];
queue<pair<int, int> > q;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int visited[8][8]={0,};

int fireon(){
    
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nextx = curx+dx[i];
            int nexty = cury+dy[i];
            if(nextx>=0&&nextx<n&&nexty>=0&&nexty<m&&visited[nextx][nexty]==0&&arr[nextx][nexty]!=1){
                visited[nextx][nexty] = 1;
                q.push(make_pair(nextx,nexty));
                arr[nextx][nexty] = 2;
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0)
                res++;
        }
    }
    return res;
}

int maxres = 0;
vector<pair<int, int> > vec;
void select(int cnt){
    if(cnt==3){
        memset(visited,0,sizeof(visited));
        int flag = 0;
        for(int i=0;i<vec.size()-1;i++){
            for(int j=i+1;j<vec.size();j++){
                if(vec[i].first==vec[j].first&&vec[i].second==vec[j].second){
                    flag = 1;
                }
            }
        }
        if(flag==1)
            return;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(realarr[i][j]==2){
                    visited[i][j] = 1;
                    q.push(make_pair(i,j));
                }
                arr[i][j] = realarr[i][j];
            }
        }
        for(int i=0;i<vec.size();i++){
            arr[vec[i].first][vec[i].second] = 1;
        }
        int nowres = fireon();
        if(maxres<nowres)
            maxres = nowres;
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(realarr[i][j]==0){
                vec.push_back(make_pair(i,j));
                select(cnt+1);
                vec.pop_back();
            }
        }
    }
}

int main(){
    cin>>n>>m;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp;
            cin>>tmp;
            realarr[i][j] = tmp;
        }
    }
    select(0);
    cout <<maxres;
}
