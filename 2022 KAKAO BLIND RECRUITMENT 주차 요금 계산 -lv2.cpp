#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> ma;
    map<string, int> fee;
    for(int i=0;i<records.size();i++){
        string s = records[i];
        string carn = s.substr(6,4); //차량번호
        string inout = s.substr(11);
        if(inout=="IN"){
            ma[carn] = s.substr(0,5);
        }
        else{
            auto it = ma.find(carn);
            int nowfee;
            string outtime = it->second;
            int h=0;
            int m=0;
            for(int i=0;i<2;i++){
                int outime = s[i] - '0';
                int intime = outtime[i]-'0';
                h = h*10+(outime-intime);
            }
            for(int i=3;i<5;i++){
                int outime = s[i] - '0';
                int intime = outtime[i] - '0';
                m = m*10+(outime-intime);
            }
            m = m+ h*60;
            auto itt = fee.find(carn);
            if(itt!=fee.end())
                fee[carn]+=m;
            else{
                fee[carn] = m;
            }
            ma.erase(carn);
        }
    }
    for(auto it=ma.begin();it!=ma.end();++it){
        string carn = it->first;
        string outtime = "23:59";
        int h=0;
        int m=0;
        for(int i=0;i<2;i++){
            int intime = it->second[i] - '0';
            int outime = outtime[i]-'0';
            h = h*10+(outime-intime);
        }
        for(int i=3;i<5;i++){
            int intime = it->second[i] - '0';
            int outime = outtime[i] - '0';
            m = m*10+(outime-intime);
        }
        m = m+ h*60;
        auto itt = fee.find(carn);
        if(itt!=fee.end())
            fee[carn]+=m;
        else{
            fee[carn] = m;
        }
        
    }
    for(auto it=fee.begin();it!=fee.end();++it){
        int min = it->second;
        if(fees[0]>=min)
            answer.push_back(fees[1]);
        else{
            int total = fees[1];
            min = min-fees[0];
            if(min%fees[2]==0)
                total+= min/fees[2]*fees[3];
            else{
                total+= (min/fees[2]+1)*fees[3];
            }
            answer.push_back(total);
        }
    }
        //cout << it->first << " " << it->second << " \n";
    return answer;
}
