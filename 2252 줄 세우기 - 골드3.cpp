#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int inp[32001];
vector<int> arr[32001];

int main(){
    int n,m;
    cin>>n>>m;
    memset(inp,0,sizeof(inp));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        inp[b]++;
        arr[a].push_back(b);
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(inp[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int tmp = q.front();
        cout << tmp << " ";
        q.pop();
        for(int i=0;i<arr[tmp].size();i++){
            inp[arr[tmp][i]]--;
            if(inp[arr[tmp][i]]==0)
                q.push(arr[tmp][i]);
        }
    }
    
}
