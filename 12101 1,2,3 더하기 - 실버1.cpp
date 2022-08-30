#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n,k;
priority_queue<string,vector<string>, greater<string> > res;

void fnd(){
    queue<pair<string, int> > q;
    q.push(make_pair("1",1));
    q.push(make_pair("2",2));
    q.push(make_pair("3",3));
    while(!q.empty()){
        int sum = q.front().second;
        string sik = q.front().first;
        q.pop();
        if(sum==n){
            res.push(sik);
            continue;
        }
        if(sum<n){
            q.push(make_pair(sik+"+1",sum+1));
            q.push(make_pair(sik+"+2",sum+2));
            q.push(make_pair(sik+"+3",sum+3));
        }
    }
}
int main(){
    cin>>n>>k;
    fnd();
    int i =1;
    while(!res.empty()){
        if(i==k){
            cout << res.top() <<"\n";
            return 0;
        }
        i++;
        res.pop();
    }
    cout << -1;
}
