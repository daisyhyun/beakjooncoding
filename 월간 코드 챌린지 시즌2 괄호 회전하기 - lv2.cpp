#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int strlen = s.length();
    for(int i=0;i<strlen;i++){
        vector<char> vec;
        int flag = 1;
        for(int j=0;j<strlen;j++){
            if(s[j]=='('||s[j]=='{'||s[j]=='['){
                vec.push_back(s[j]);
            }
            else{
                if(vec.empty()){
                    flag = 0;
                    break;
                }
                if(s[j]==')'&&vec.back()=='('){
                    vec.pop_back();
                }
                if(s[j]=='}'&&vec.back()=='{'){
                    vec.pop_back();
                }
                if(s[j]==']'&&vec.back()=='['){
                    vec.pop_back();
                }
            }
        }
        if(flag==1&&vec.empty()){
            answer++;
        }
        string tmps = "";
        for(int p = 1;p<strlen;p++){
            tmps+=s[p];
        }
        tmps+=s[0];
        s = tmps;
    }
    return answer;
}
