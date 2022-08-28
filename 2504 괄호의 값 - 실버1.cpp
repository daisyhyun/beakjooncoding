#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<char> sik;
int main(){
    string s;
    cin>>s;
    int lensize = s.length();
    int tmp = 1;
    int res = 0;
    for(int i=0;i<lensize;i++){
        if(s[i]=='('){
            tmp*=2;
            sik.push_back('(');
        }
        else if(s[i]=='['){
            tmp*=3;
            sik.push_back('[');
        }
        else if(s[i]==')'){
            if(sik.empty()||sik.back()!='('){
                cout << 0;
                return 0;
            }
            if(s[i-1]=='('){
                res+=tmp;
            
            }
            tmp/=2;
            sik.pop_back();
        }
        else if(s[i]==']'){
            if(sik.empty()||sik.back()!='['){
                cout << 0;
                return 0;
            }
            if(s[i-1]=='[')
                res+=tmp;
            tmp/=3;
            sik.pop_back();
        }
    }
    if(!sik.empty())
        cout <<0;
    else
        cout << res;
}
