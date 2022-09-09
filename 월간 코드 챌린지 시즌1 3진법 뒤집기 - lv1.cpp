#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int tmp = n;
    vector<int> v;
    while(tmp!=0){
        v.push_back(tmp%3);
        tmp /=3;
    }
    int pow =1;
    while(!v.empty()){
        answer+=v.back()*pow;
        v.pop_back();
        pow*=3;
    }
    
    return answer;
}
