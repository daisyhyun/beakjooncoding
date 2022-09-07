#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int row =0;
    int col =0;
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][1]>sizes[i][0]){
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
        if(row<sizes[i][0])
            row = sizes[i][0];
        if(col<sizes[i][1])
            col = sizes[i][1];
    }
    answer = row*col;
    return answer;
}
