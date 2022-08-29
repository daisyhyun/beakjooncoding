#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,s,e;
vector<pair<int,int> > graph[1001];
long long dist[1001];

void bfs(){
    priority_queue<pair<long long,int> ,vector<pair<long long,int> >, greater<pair<long long,int> > > pq;
    pq.push(make_pair(0,s));
    dist[s]=0;
    while(!pq.empty()){
        int now= pq.top().second;
        long long weight = pq.top().first;
        pq.pop();
        if(dist[now]<weight)
            continue;
        for(int i=0;i<graph[now].size();i++){
            long long cost = graph[now][i].second+weight;
            if(dist[graph[now][i].first]>cost){
                dist[graph[now][i].first]=cost;
                pq.push(make_pair(cost,graph[now][i].first));
            }
            
        }
    }
}

int main(){
    cin>>n;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
    }
    cin>>s>>e;
    for(int i=1;i<=n;i++)
        dist[i]=100000001;
    //cout << "?";
    bfs();
    cout << dist[e];
}
