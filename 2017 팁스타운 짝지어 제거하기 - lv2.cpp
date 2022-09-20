#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = -1;
    string tmp = s;
    vector<char> vec;
    vec.push_back(s[0]);
    for(int i=1;i<s.length();i++){
        if(vec.back()==s[i]){
            vec.pop_back();
        }
        else{
            vec.push_back(s[i]);
        }
    }
    if(vec.size()==0)
        return 1;
    return 0;
}
