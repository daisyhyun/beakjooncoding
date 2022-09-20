#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int front = 0;
    int back = people.size()-1;
    while(front<=back){
        if(people[front]+people[back]<=limit){
            answer++;
            front++;
            back--;
        }
        else{
            answer++;
            back--;
        }
    }
    return answer;
}
