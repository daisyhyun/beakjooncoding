#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int k,m,p;
vector<int> liv[1001];
int stra[1001][2];
int inp[1001];
int res;
void fnd(){
    queue<int> q;
    for(int i=1;i<=m;i++){
        if(inp[i]==0){
            q.push(i);
            stra[i][0]=1;
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        res = max(res,stra[now][0]);
        for(int i=0;i<liv[now].size();i++){
            inp[liv[now][i]]--;
            if(stra[liv[now][i]][0]<stra[now][0]){
                stra[liv[now][i]][0] = stra[now][0];
                stra[liv[now][i]][1] =1;
            }
            else if(stra[liv[now][i]][0]==stra[now][0])
                stra[liv[now][i]][1]++;
            if(inp[liv[now][i]]==0){
                q.push(liv[now][i]);
                if(stra[liv[now][i]][1]>=2)
                    stra[liv[now][i]][0]++;
                
            }
                
        }
    }
}

int main(){
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>k>>m>>p;
        for(int i=0;i<=1000;i++)
            liv[i].clear();
        memset(inp,0,sizeof(inp));
        for(int i=1;i<=m;i++){
            stra[i][0]=0;
            stra[i][1]=0;
        }
        for(int i=0;i<p;i++){
            int a,b;
            cin>>a>>b;
            liv[a].push_back(b);
            inp[b]++;
        }
        res = 0;
        fnd();
        cout << k<< " " <<res<<"\n";
    }
}
