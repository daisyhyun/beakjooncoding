#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int arr[10001] = {0,};
    int maxn = 0;
    for(int i=0;i<citations.size();i++){
        arr[citations[i]]++;
        maxn = max(maxn,citations[i]);
    }
    int res[10001] = {0,};
    res[0] = citations.size();
    for(int i=1;i<=maxn;i++){
        res[i] = res[i-1]-arr[i-1];
        if(res[i]>=i){
            answer = max(answer,i);
        }
    }
    return answer;
}
