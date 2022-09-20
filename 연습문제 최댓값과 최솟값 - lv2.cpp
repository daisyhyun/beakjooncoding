#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    int strlen = s.length();
    vector<int> res;
    int tmp =0;
    int flag = 0;
    int isnum =0;
    for(int i=0;i<=strlen;i++){
        if(isspace(s[i])||i==strlen){
            if(flag==1)
                res.push_back(-tmp);
            else{
                res.push_back(tmp);
            }
            flag = 0;
            tmp = 0;
        }
        else{
            if(s[i]=='-'){
                flag = 1;
            }
            else{
                tmp*=10;
                tmp+=s[i]-'0';
            }
        }
    }
    int minnum=res[0];
    int maxnum=res[0];
    for(int k : res){
        minnum = min(minnum,k);
        maxnum = max(maxnum,k);
    }
    answer = to_string(minnum) + " "+to_string(maxnum);
    return answer;
}
