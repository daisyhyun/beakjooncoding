#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
//int arr[8];
vector<int> arr;
vector<int> com;
int visited[10];
void comb(int cnt){
    if(cnt==m){
        for(int tmp:com)
            cout<<tmp <<" ";
        cout << "\n";
    }
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            visited[i]=1;
            com.push_back(arr[i]);
            comb(cnt+1);
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
    comb(0);
}
