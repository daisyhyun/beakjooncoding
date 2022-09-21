#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> res;
    int visited[101] = {0,};
    int sum = 0;
    int len = progresses.size();
    int cnt = 1;
    int time = (100-progresses[0])/speeds[0];
    if((100-progresses[0])%speeds[0]!=0)
        time++;
    for(int i=1;i<progresses.size();i++){
        int left = 100-progresses[i];
        int ttime = left / speeds[i];
      //  cout << ttime << "\n";
        if(left%speeds[i]!=0)
            ttime++;
        if(ttime<=time){
            cnt++;
            continue;
        }
        time = ttime;
        if(cnt!=0){
            res.push_back(cnt);
            cnt = 1;
        }
    }
    res.push_back(cnt);
    return res;
}
