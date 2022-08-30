#include<iostream>
#include<queue>


using namespace std;
int n,m;
priority_queue<string> pq;
void fnd(int start,int cnt,string st){
    if(cnt==m){
        for(int i=0;i<st.length();i++)
            cout << st[i]<<" ";
        cout <<"\n";
        return;
    }
    for(int i=start;i<=n;i++){
        fnd(i+1,cnt+1,st+to_string(i));
    }
}

int main(){
    cin >>n>>m;
    string res;
    fnd(1,0,res);
}  
