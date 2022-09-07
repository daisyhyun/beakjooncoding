#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    map<char,int> arr;
    for(int i=0;i<survey.size();i++){
        char x = survey[i][0];
        char o = survey[i][1];
        int score = choices[i];
        switch (score){
            case 1:
                arr[x]+=3;
                break;
            case 2:
                arr[x]+=2;
                break;
            case 3:
                arr[x]+=1;
                break;
            case 5:
                arr[o]+=1;
                break;
            case 6:
                arr[o]+=2;
                break;
            case 7:
                arr[o]+=3;
                break;
            default:
                break;
                
        }
    }
    
    vector<pair<int, char> > v;
    for(auto it=arr.begin();it!=arr.end();++it){
        v.push_back(make_pair(it->second,it->first));
    }
    sort(v.begin(),v.end(),greater());
    int sum=0;
    char res[5];
    int visited[4][2];
    memset(visited,0,sizeof(visited));
    res[4] = '\0';
    for(auto tmp:v){
        if(tmp.second=='R'||tmp.second=='T'){
            if(visited[0][0]==0){
                visited[0][0]=1;
                visited[0][1]=tmp.first;
                res[0]=tmp.second;
                sum++;
            }
            else{
                if(visited[0][1]==tmp.first){
                    res[0]='R';
                }
            }
        }
        else if(tmp.second=='C'||tmp.second=='F'){
            if(visited[1][0]==0){
                visited[1][0]=1;
                visited[1][1]=tmp.first;
                res[1]=tmp.second;
                sum++;
            }
            else{
                if(visited[1][1]==tmp.first){
                    res[1]='C';
                }
            }
        }
        else if(tmp.second=='J'||tmp.second=='M'){
            if(visited[2][0]==0){
                visited[2][0]=1;
                visited[2][1]=tmp.first;
                res[2]=tmp.second;
                sum++;
            }
            else{
                if(visited[2][1]==tmp.first){
                    res[2]='J';
                }
            }
        }
        else{
            if(visited[3][0]==0){
                visited[3][0]=1;
                visited[3][1]=tmp.first;
                res[3]=tmp.second;
                sum++;
            }
            else{
                if(visited[3][1]==tmp.first){
                    res[3]='A';
                }
            }
        }
    }
    if(sum==4){
        return res;
    }
    else{
        if(visited[0][0]==0){
            res[0]='R';
        }
        if(visited[1][0]==0){
            res[1]='C';
        }
        if(visited[2][0]==0){
            res[2]='J';
        }
        if(visited[3][0]==0){
            res[3]='A';
        }
        return res;
    }
}
