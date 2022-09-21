#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    if(a.size()>b.size())
        return false;
    else
        return true;
}

vector<int> solution(string s) {
    vector<int> answer;
    int lopen = 0;
    vector<vector<int> > vec;
    int tmp=0;
    vector<int> k;
    for(int i=1;i<s.length()-1;i++){
        if(s[i]=='{'){
            lopen = 1;
            continue;
        }
        if(s[i]=='}'){
            lopen = 0;
            k.push_back(tmp);
            vec.push_back(k);
            k.clear();
            tmp = 0;
        }
        if(lopen==1){
            if(s[i]==','){
                k.push_back(tmp);
                tmp = 0;
                continue;
            }
            tmp= tmp*10+(s[i]-'0');
        }
        
    }
    sort(vec.begin(),vec.end(),compare);
    map<int, int> m;
    for(auto tmp : vec){
        for(auto k : tmp){
            auto it = m.find(k);
            if(it!=m.end())
                continue;
            m[k] = 1;
            answer.push_back(k);
        }
    }
    return answer;
}
