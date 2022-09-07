#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, vector<string> > res;
    vector<pair<string, string> > rep;
    for(string it:report){
        string reporter = it.substr(0,it.find(" "));
        string reported = it.substr(it.find(" ")+1,it.length());
        rep.push_back(make_pair(reporter,reported));
    }
    sort(rep.begin(),rep.end());
    rep.erase(unique(rep.begin(),rep.end()),rep.end());
    for(auto it : rep){
        res[it.second].push_back(it.first);
    }
    int arr[1001]={0,};
    for(int i=0;i<id_list.size();i++){
        auto fnd = res.find(id_list[i]);
        if (fnd != res.end()){
            if(fnd->second.size()>=k){
                for(int j=0;j<fnd->second.size();j++){
                    for(int p=0;p<id_list.size();p++){
                        if(fnd->second[j].compare(id_list[p])==0){
                            arr[p]++;
                            break;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<id_list.size();i++)
        answer.push_back(arr[i]);
    return answer;
}
