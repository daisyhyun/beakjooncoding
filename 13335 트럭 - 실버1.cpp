#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n,w,l;
int arr[1000];
queue<int> q;
int ledlen[1001];
int main(){
    cin>>n>>w>>l;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        q.push(tmp);
    }
    int ledsum=0;
    int time=0;
    memset(ledlen,0,sizeof(ledlen));
    while(!q.empty()){
        int outweight = ledlen[w];
        for(int i=w;i>1;i--){
            ledlen[i]=ledlen[i-1];
        }
        ledlen[1] = 0;
        ledsum-=outweight;
        if(l>=ledsum+q.front()){
            ledlen[1] = q.front();
            ledsum+=q.front();
            q.pop();
        }
        time++;
    }
    cout << time+w;
}
