#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<pair<string, int> >vec;
    int time = 0;
    if(cacheSize==0)
        return 5*cities.size();
    for(int i=0;i<cities.size();i++){
        int lrut=cities.size();
        int idx;
        int flag = 0;
        for(int j=0;j<vec.size();j++){
            if(lrut>vec[j].second){
                lrut = vec[j].second;
                idx = j;
            }
            if(!strcasecmp(vec[j].first.c_str(),cities[i].c_str())){
                flag = 1;
                vec[j].second = i;
                break;
            }
        }
        if(flag==1){
            
            time++;
        }
            
        else{
            if(vec.size()>=cacheSize){
               vec.erase(vec.begin()+idx);
            }
            vec.push_back(make_pair(cities[i],i));
            time+=5;
        }
    }
    return time;
}
