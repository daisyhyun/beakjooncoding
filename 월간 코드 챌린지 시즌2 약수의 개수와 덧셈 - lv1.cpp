#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int tmp = 1;
    while(tmp*tmp<left) tmp++;
    answer = (left+right)*(right-left+1)/2;
    while(tmp*tmp<=right){
        answer-=(tmp*tmp)*2;
        tmp++;
    }
    return answer;
}
