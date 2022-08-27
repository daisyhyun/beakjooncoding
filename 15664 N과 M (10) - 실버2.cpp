#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int n,m;
vector<int> arr;
vector<int> com;
vector<vector<int> > res;
int visited[10];
void comb(int start,int cnt){
    if(cnt==m){
        res.push_back(com);
    }
    for(int i=start;i<arr.size();i++){
        if(visited[i]==0){
            visited[i]=1;
            com.push_back(arr[i]);
            comb(i+1,cnt+1);
            visited[i]=0;
            com.pop_back();
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    memset(visited,0,sizeof(visited));
    sort(arr.begin(),arr.end());
    comb(0,0);
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    for(auto tmp:res){
        for(int temp:tmp)
            cout<< temp <<" ";
        cout <<"\n";
    }
}
