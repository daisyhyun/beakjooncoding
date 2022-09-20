#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m;
    int id = 1;
    int turn = 1;
    for(int i=0;i<words.size();i++){
        string nowword = words[i];
        auto isin = m.find(nowword);
        if(isin != m.end()){
            answer.push_back(id);
            answer.push_back(turn);
            return answer;
        }
        if(i!=0){
            int wordsize = words[i-1].length();
            if(words[i-1][wordsize-1]!=nowword[0]){
               // cout << words[i-1][wordsize-1] << " " <<nowword[0];
                answer.push_back(id);
                answer.push_back(turn);
                return answer;
            }
        }
        m[nowword] = id;
        id++;
        if(id>n){
            id=1;
            turn++;
        }
            
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}
