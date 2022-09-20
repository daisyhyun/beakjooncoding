#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int sum = 0;
    while(s!="1"){
        string tmp="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')
                sum++;
            else
                tmp +="1";
        }
        int tmpsize = tmp.length();
        string tmps = "";
        while(tmpsize!=0){
            tmps+= to_string(tmpsize%2);
            tmpsize /=2;
        }
        s = "";
        for(int i = 0;i<tmps.length();i++){
            s+=tmps[tmps.length()-i-1];
        }
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(sum);
    return answer;
}
