#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[6][3];
int marr[6][3];
int visited[15];
vector<int> pr;
int isable;
vector<vector<int> > sun;
vector<int> res;

void makeround(int start,int cnt){
    if(cnt==2){
        sun.push_back(pr);
    }
    for(int i=start;i<6;i++){
        if(visited[i]==0){
            visited[i]=1;
            pr.push_back(i);
            makeround(i+1,cnt+1);
            visited[i]=0;
            pr.pop_back();
        }
    }
}

void bfs(int cnt){
    if(cnt==sun.size()){
        int flag =1;
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                if(marr[i][j]!=arr[i][j]){
                    flag = 0;
                    return;
                }
            }
        }
        if(flag==1)
            isable=1;
        return;
    }
    marr[sun[cnt].front()][0]++;
    marr[sun[cnt].back()][2]++;
    bfs(cnt+1);
    marr[sun[cnt].front()][0]--;
    marr[sun[cnt].back()][2]--;
    marr[sun[cnt].front()][1]++;
    marr[sun[cnt].back()][1]++;
    bfs(cnt+1);
    marr[sun[cnt].front()][1]--;
    marr[sun[cnt].back()][1]--;
    marr[sun[cnt].front()][2]++;
    marr[sun[cnt].back()][0]++;
    bfs(cnt+1);
    marr[sun[cnt].front()][2]--;
    marr[sun[cnt].back()][0]--;

}

int main(){
    makeround(0,0);
    for(int k=0;k<4;k++){
        int flag =0;
        isable = 0;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                cin>>arr[i][j];
            }
        }
        bfs(0);
        res.push_back(isable);
    }
    for(int tmp:res)
        cout<<tmp << " ";
    
}
