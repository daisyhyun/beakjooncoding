#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n,m;
int arr[21][21];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<pair<int, int> > axis;
int res = 11;
void dfs(int x1,int y1, int x2, int y2,int cnt){
    if(cnt==11){
        return;
    }
    for(int i=0;i<4;i++){
        int tmpx1,tmpy1,tmpx2,tmpy2;
        int outcnt = 0;
        int dom1=0;
        int dom2=0;
        tmpx1 = x1+dx[i];
        tmpy1 = y1+dy[i];
        tmpx2 = x2+dx[i];
        tmpy2 = y2+dy[i];
        if(tmpx1<0||tmpx1>=n||tmpy1<0||tmpy1>=m){
            outcnt++;
        }
        else if(arr[tmpx1][tmpy1]==1){
            tmpx1 = x1;
            tmpy1 = y1;
        }
        if(tmpx2<0||tmpx2>=n||tmpy2<0||tmpy2>=m){
            outcnt++;
        }
        else if(arr[tmpx2][tmpy2]==1){
            tmpx2 = x2;
            tmpy2 = y2;
        }
        if(outcnt==1){
            res = min(res,cnt);
            return;
        }
        else if(outcnt==2){
            continue;
        }
        else{
            dfs(tmpx1,tmpy1,tmpx2,tmpy2,cnt+1);
        }
    }
}
int main(){
    cin>>n>>m;
    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='o'){
                axis.push_back(make_pair(i,j));
            }
            if(s[j]=='#'){
                arr[i][j]=1;
            }  
        }
    }
    dfs(axis[0].first,axis[0].second,axis[1].first,axis[1].second,1);
    if(res==11)
        res = -1;
    cout << res;
}
