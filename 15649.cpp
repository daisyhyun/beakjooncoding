#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> v;
int n,m;
int visited[9];
void comb(int cnt){
    if(cnt==m){
        for(int tmp:v)
            cout<<tmp <<" ";
        cout << "\n";
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            visited[i] = 1;
            v.push_back(i);
            comb(cnt+1);
            v.pop_back();
            visited[i] = 0;
        }
    }
}


int main(){
    cin >>n>>m;
    memset(visited,0,sizeof(visited));
    comb(0);
}
