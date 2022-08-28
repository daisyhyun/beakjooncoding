#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int arr[12][12];
int visited[12];
int res;
void dfs(int cnt,int sum){
    if(cnt==11){
        res = max(res,sum);
        return;
    }
    for(int i=0;i<11;i++){
        if(visited[i]==0&&arr[cnt][i]!=0){
            visited[i]=1;
            dfs(cnt+1,sum+arr[cnt][i]);
            visited[i]=0;
        }
    }
}

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        memset(visited,0,sizeof(visited));
        res = 0;
        for(int p=0;p<11;p++){
            for(int q=0;q<11;q++){
                cin>> arr[p][q];
            }
        }
        dfs(0,0);
        cout << res <<"\n";
    }
}
