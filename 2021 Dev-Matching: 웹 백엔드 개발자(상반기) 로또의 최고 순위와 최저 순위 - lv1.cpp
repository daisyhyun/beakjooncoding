#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int same=0;
    int x = 0;
    for(int i=0;i<6;i++){
        if(lottos[i]==0){
            x++;
            continue;
        }
        for(int j=0;j<6;j++){
            if(lottos[i]==win_nums[j])
                same++;
        }
    }
    int high = 7-same-x;
    int low = 7-same;
    if(high>6)
        high = 6;
    if(low>6)
        low = 6;
    answer.push_back(high);
    answer.push_back(low);
    return answer;
}
