#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int v,e;
long long res;
int par[10001];
vector<pair<pair<int,int>, int> > kus;
bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    if(a.second>b.second)
        return true;
    else
        return false;
}

int findpar(int a){
    int tmp = a;
    while(par[tmp]!=tmp){
        tmp = par[tmp];
    }
    par[a]=tmp;
    return tmp;
}

void mst(){
    int cnt =0;
    while(cnt<v-1){
        auto tmp = kus.back();
        int a = tmp.first.first;
        int b = tmp.first.second;
        int c = tmp.second;
        if(findpar(a)==findpar(b)){
            kus.pop_back();
            continue;
        }
        par[findpar(a)] = par[findpar(b)];
        cnt++;
        res+=c;
        kus.pop_back();
    }
}


int main(){
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        kus.push_back(make_pair(make_pair(a,b),c));
    }
    for(int i=0;i<=v;i++)
        par[i]=i;
    res = 0;
    sort(kus.begin(),kus.end(),comp);
    mst();
    cout << res;
}
