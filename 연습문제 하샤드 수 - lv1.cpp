#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int tmp = x;
    int hasha = 0;
    while(tmp!=0){
        hasha += tmp%10;
        tmp /= 10;
    }
    if(x%hasha!=0)
        answer = false;
    return answer;
}
