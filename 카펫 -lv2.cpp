#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1;i*i<=yellow;i++){
        if(yellow%i==0){
            int yels = i;
            int yeld = yellow/yels;
            if((yels+2)*(yeld+2)==brown+yellow){
                answer.push_back(yeld+2);
                answer.push_back(yels+2);
                
                return answer;
            }
        }
    }
    //return answer;
}
