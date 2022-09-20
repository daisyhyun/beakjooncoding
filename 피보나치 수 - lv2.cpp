#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);
    for(int i=3;i<=n;i++){
        vec.push_back((vec[i-2]+vec[i-1])%1234567);
    }
    return vec.back();
}
