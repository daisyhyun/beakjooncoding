#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n,l,r,x;
int arr[15];
int res;
int fp;
int visited[15];
void dfs(int start,int cnt){
    if(cnt==fp){
        int les=1000001;
        int mx =0;
        int tmpsum=0;
        for(int i=0;i<n;i++){
            if(visited[i]==1){
                if(les>arr[i])
                    les = arr[i];
                if(mx<arr[i])
                    mx = arr[i];
                tmpsum += arr[i];
            }
        }
        if(tmpsum>=l&&tmpsum<=r&&mx-les>=x)
            res++;
        return;
    }
    for(int i=start;i<n;i++){
        if(visited[i]==0){
            visited[i]=1;
            dfs(i+1,cnt+1);
            visited[i]=0;
        }
    }
}

int main(){
    cin>>n>>l>>r>>x;
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=2;i<=n;i++){
        memset(visited,0,sizeof(visited));
        fp = i;
        dfs(0,0);
    }
    cout << res;
}
