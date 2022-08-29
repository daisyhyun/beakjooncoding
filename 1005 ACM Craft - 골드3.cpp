#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n,k,w;
vector<int> d[1001];
int inp[1001][2];
int delay[1001];

void fnd(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(inp[i][0]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<d[now].size();i++){
            int tmp = d[now][i];
            inp[tmp][0]--;
            inp[tmp][1] = max(inp[tmp][1],delay[now]);
            if(inp[tmp][0]==0){
                delay[tmp]+=inp[tmp][1];
                q.push(tmp);
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            inp[i][0]=0;
            inp[i][1]=0;
            d[i].clear();
        }
        for(int i=1;i<=n;i++)
            cin>>delay[i];
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            d[x].push_back(y);
            inp[y][0]++;
        }
        cin>>w;
        fnd();
        cout << delay[w]<<"\n";
    }
}
