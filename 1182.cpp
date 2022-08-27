#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int n,s,res;
int arr[20];
vector<int> v;
int visited[20];
void comb(int start,int cnt){
    if(v.size()==cnt){
        int sum = 0;
        for(int tmp:v){
            sum+=arr[tmp];
        }
        if(sum==s)
            res++;
        return ;
    }
    for(int i=start;i<n;i++){
        if(visited[i]==0){
            visited[i]=1;
            v.push_back(i);
            comb(i+1,cnt);
            visited[i]=0;
            v.pop_back();
        }
    }
}

int main(){
    cin>>n>>s;
    res= 0;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        v.clear();
        comb(0,i);
    }
    cout << res;
}
