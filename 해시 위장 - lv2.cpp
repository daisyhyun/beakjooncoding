#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> m;
    for(int i=0;i<clothes.size();i++){
        auto it = m.find(clothes[i][1]);
        if(it!=m.end()){
            m[clothes[i][1]]+=1;
        }
        else{
            m[clothes[i][1]] = 1;
        }
    }
    int sum = 1;
    for(auto it = m.begin();it!=m.end();++it){
        sum = sum*(it->second+1);
    }
    return sum-1;
}
