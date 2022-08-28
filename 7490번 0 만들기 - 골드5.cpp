#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int visited[10];
int num;
vector<string> resstr;
void dfs(int start, int cnt,string st){
    if(cnt==num){
        int stlen = st.size();
        int res = 0;
        int k = 1;
        int savnum=0;
        int flag = 1;
        for(int i=0;i<stlen;i++){
            if(st[i]=='+'){
                if(flag==1){
                    res+=savnum;
                    k=1;
                    savnum=0;
                }
                else{
                    res-=savnum;
                    k=1;
                    savnum=0;
                    flag = 1;
                }
            }
            else if(st[i]=='-'){
                if(flag==1){
                    res+=savnum;
                    k=1;
                    savnum=0;
                    flag = 0;
                }
                else{
                    res-=savnum;
                    k=1;
                    savnum=0;
                }
            }
            else if(st[i]==' '){
                savnum*=10;
            }
            else{
                savnum+= (st[i]-'0');
            }
        }
        if(flag==1){
            res+=savnum;
        }
        else{
            res-=savnum;
        }
        if(res==0)
            resstr.push_back(st);
        return;
    }
    dfs(start+1,cnt+1,st+'+'+to_string(start));
    dfs(start+1,cnt+1,st+'-'+to_string(start));
    dfs(start+1,cnt+1,st+' '+to_string(start));

}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        memset(visited,0,sizeof(visited));
        resstr.clear();
        cin >> num;
        string s;
        s+='1';
        dfs(2,1,s);
        sort(resstr.begin(),resstr.end());
        for(auto tmp:resstr)
            cout << tmp<<'\n';
        cout << "\n";
    }   
}
