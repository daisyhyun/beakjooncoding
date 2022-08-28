#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
int n,k;
vector<char> s;
vector<string> str;
int res;
char ch[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int visited[26];
void dfs(int start,int cnt){
    if(cnt==k){
        int tmpres=0;
        for(int i=0;i<str.size();i++){
            string tmp = str[i];
            int flag;
            for(int j=0;j<tmp.length();j++){
                flag = 0;
                for(auto temp : s){
                    if(tmp[j]==temp){
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    break;
            }
            if(flag==1){
                tmpres++;
            }
        }
        res = max(res,tmpres);
        return;
    }
    for(int i=start;i<26;i++){
        if(visited[i]==0){
            s.push_back(ch[i]);
            visited[i]=1;
            dfs(i+1,cnt+1);
            s.pop_back();
            visited[i]=0;
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        string p;
        cin>>p;
        str.push_back(p);
    }
    res = 0;
    if(k<5){
        cout << 0;
        return 0;
    }
    memset(visited,0,sizeof(visited));
    s.push_back('a');
    s.push_back('c');
    s.push_back('i');
    s.push_back('n');
    s.push_back('t');
    visited[0]=1;
    visited[2]=1;
    visited[8]=1;
    visited[13]=1;
    visited[19]=1;
    dfs(0,5);
    cout << res;
}
