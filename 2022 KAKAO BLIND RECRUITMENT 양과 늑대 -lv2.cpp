#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
vector<int> vec[18];
int res = 0;
void bfs(int now, int yang, int nuk, queue<int> q,vector<int> info){
    if(info[now]==0)
        yang++;
    else
        nuk++;
    if(nuk>=yang)
        return;
    if(res<yang)
        res = yang;
    for(int i=0;i<vec[now].size();i++){
        q.push(vec[now][i]);
    }
    for(int i=0;i<q.size();i++){
        int next = q.front();
        q.pop();
        bfs(next,yang,nuk,q,info);
        q.push(next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    for(int i=0;i<edges.size();i++){
        vec[edges[i][0]].push_back(edges[i][1]);
    }
    queue<int> q;
    bfs(0,0,0,q,info);
    return res;
}
